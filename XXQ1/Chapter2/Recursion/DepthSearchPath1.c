#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define Status int
#define EqualFun strcmp
#define SetValue strcpy
#define NAMESIZE 3
#define TRUE 1
#define FALSE 0

typedef char Node[NAMESIZE];

typedef struct BrotherNode                          
{
    Node node;
    struct BrotherNode *next;
} BrotherNode, *Brother;

typedef struct ParentNode
{
    Node node;
    Brother children;
} ParentNode, Parent;

typedef struct TreeNode
{
    Parent node;
    struct TreeNode *next;
} TreeNode, *Tree;

//路径结构设计
typedef struct BrotherNode *Path;

typedef struct Paths
{
    Path path;
    struct Paths *next;
} Paths, *PathsPointer;


//1.通用比较函数
int Equal(Node n1, Node n2, int fun(const Node n1, const Node n2));

//2.通用赋值函数
void Set(Node n1, Node n2, char *fun(Node n1, const Node n2));

//3.兄弟节点关系创建
Brother AddBrother(Brother br, Node node);

//3.1 兄弟显示
void priBrothers(Brother brother);


//4.双亲与子节点关系的构建
Tree Form_Pa_Ch(Node pa, Brother br);

//5.将带子节点的双亲节点加入到树种
Tree AddsubTree(Tree tree, Tree subtree);

//6.清除兄弟节点和树
Brother ClearBrothers(Brother br);

//7.ClearTree 清空树， 回收数据单元
Tree ClearTree(Tree tree);

//8.字符数组转换
void CreateStr(char *brotherset);

//9.字符数组建立兄弟关系
Brother CreateBrothers(Brother brothers, char *brotherset);

//10.根据树文件建立树
Tree CreateTree(Tree tree, char *filename);

//树搜索实现

//1.复制子节点集
Brother CopyBrothers(Brother children);

//2.扩展节点集
Brother ExpandNodes(Tree tree, Node pa);

//路径

//1.节点加入路径
Path AddNodeToPath(Node node, Path path);

//2.复制路径与路径集合

//2.1复制一条路径
Path CopyPath(Path path);

//2.2复制路径集合
PathsPointer CopyPaths(PathsPointer paths);

//3.路径倒序与显示

//3.1路径倒序
void RevPath(Path path);

//3.2显示路径
void priPath(Path path);
//4.路径加入路径集合
PathsPointer AddPathToPaths(Path path, PathsPointer paths);

//5.节点集合与路径集合形成路径集合
PathsPointer FormPathsFromNodes(Brother brothers, Path path, PathsPointer paths);

//6.回收路径与路径集合空间

//6.1回收路径空间
Path ClearPath(Path path);

//6.2回收路径集合空间
PathsPointer ClearPaths(PathsPointer paths);

//1.通用比较函数
int Equal(Node n1, Node n2, int fun(const Node n1, const Node n2))
{
    return (int) fun(n1, n2);
}

//2.通用赋值函数
void Set(Node n1, Node n2, char *fun(Node n1, const Node n2))
{
    fun(n1, n2);
}

//3.兄弟节点关系创建
Brother AddBrother(Brother br, Node node)
{
    Brother b, pb;                                  //兄弟节点变量
    b = (Brother)malloc(sizeof(BrotherNode));       //动态分配
    Set(b->node, node, SetValue);                   //赋值
    b->next = NULL;                                 //b为新建节点，其下一个节点不存在

    if(br==NULL)                                    //首元结点创建
        br = b;
     else   {                                       //尾结点创建
         pb = br;                               
         while(pb->next)                            //单链表遍历至尾
             pb = pb->next;
         pb->next = b;                              //尾插操作
     }

     b = NULL;
     pb = NULL;
     return br;                                     //返回兄弟节点
}

//3.1 兄弟显示
void priBrothers(Brother brother)
{
    while(brother)  {
        printf("%s", brother->node);
        
        if(brother->next == NULL)
            break;
        printf("%s", "->");
        brother = brother->next;
    }
}

//4.双亲与子节点关系的构建
Tree Form_Pa_Ch(Node pa, Brother br)
{
    Tree parent;                                    //创建双亲结点
    parent = (Tree)malloc(sizeof(TreeNode));        //动态分配
    Set(parent->node.node, pa, SetValue);           //赋值（双亲结点的值）
    parent->node.children = br;                     //兄弟节点与双亲结点构成子树
    parent->next = NULL;                            //下一个置空

    return parent;                                  //返回
    parent = NULL;
}

//5.将带子节点的双亲节点加入到树中
Tree AddsubTree(Tree tree, Tree subtree)
{
    Tree t = tree;                                  //暂时存放原树      
    if(tree == NULL)    {                           //原树不存在
        tree = subtree;                             //直接添加
    } else  {                                       //尾插法    
        while(t->next)                              //遍历
            t = t->next;
        t->next = subtree;                          //尾插操作
      }

    return tree;                                    //返回树
}

//6.清除兄弟节点和树
Brother ClearBrothers(Brother br)
{
    Brother br1 = br;                               //临时节点
    while(br)   {                                   //遍历删除
        br1 = br;
        br = br->next;
        free(br1);
        br1 = NULL;
    }

    return br;                                      //返回NULL
}

//7.ClearTree 清空树， 回收数据单元
Tree ClearTree(Tree tree)
{
    Tree tree1 = tree;                              //临时节点标记前一个结点
    while(tree) {                                   //遍历删除
        tree1 = tree;
        tree = tree->next;
        free(tree1);
        tree1 = NULL;
    }

    return tree;                                    //返回NULL
}

//8.字符数组转换
void CreateStr(char *brotherset)
{
    char *c = brotherset;                           //临时字符串
    while(*c)   {                                   //遍历将'/'更改为'\0'
        if(*c == '/')
            *c = '\0';
        c++;
    }
    c++;
    *c = '\0';                                      //最后加一个结束标记
}

//9.字符数组建立兄弟关系
Brother CreateBrothers(Brother brothers, char *brotherset)
{
    char *p = brotherset;                           //节点值的指针
    Node node;                  
    CreateStr(brotherset);                          //转换为字符串
    
    while(*p)   {                                   //遍历
        Set(node, p, SetValue);                     //赋值，将p的值赋给node
        brothers = AddBrother(brothers, node);      //将node的值加入brothers
        p += strlen(node) + 1;                      //指针+1，指向下一个节点
    }

    return brothers;                                //返回兄弟节点链表
}

//10.根据树文件建立树
Tree CreateTree(Tree tree, char *filename)
{
    Tree subtree;
    Brother brothers;
    FILE *fp;
    char parent[100], brotherset[5000];
    fp = fopen(filename, "rt");

    while(!feof(fp))    {                           //文件中是否还存在树的节点名称
        fscanf(fp, "%s", parent);                   //读取双亲节点
        fscanf(fp, "%s", brotherset);               
        brothers = NULL;                            //读取若干个孩子节点
        brothers = CreateBrothers(brothers, brotherset);    //构建双亲节点
        subtree = Form_Pa_Ch(parent, brothers);     //构建子树
        tree = AddsubTree(tree, subtree);           //树种加入子树
    }

    fclose(fp);                                     //关闭文件
    return tree;                                    //返回所建的树
}


//树搜索实现

//1.复制子节点集
Brother CopyBrothers(Brother children)
{
    Brother copynode, lastnode, head = NULL;            //没有子节点

    while(children) {
        copynode = (Brother)malloc(sizeof(Brother));
        Set(copynode->node, children->node, SetValue);  //复制节点
        copynode->next = NULL;

        if(head == NULL)    {                           //首元结点
            head = copynode;
        } else  {                                       //建立链表，复制子节点集
            lastnode->next = copynode;
        }
        lastnode = copynode;
        children = children->next;                      //下一个子节点
    }

    free(copynode);
    copynode = NULL;

    return head;
}

//2.扩展节点集
Brother ExpandNodes(Tree tree, Node pa)
{
    //pa是树根，根据树的结构，每个纵向节点都会保留根节点
    Brother children = NULL;                                //孩子节点
    Tree t = tree;                                          //树
    while(t)    {                                           //节点不为空
        if(Equal(t->node.node, pa, EqualFun) == 0)   {      
            children = CopyBrothers(t->node.children);      //找到分支节点
            break;
        }

        t = t->next;                                        //下一个双亲节点
    }

    return children;                                        //返回所有的孩子
}



//路径

//1.节点加入路径
Path AddNodeToPath(Node node, Path path)
{
    Path p;
    p = (Brother)malloc(sizeof(BrotherNode));
    Set(p->node, node, SetValue);
    if(path == NULL)                            //路径上的第一个节点
        p->next = NULL;
    else    {                                   //头插法
        p->next = path;
    }

    path = p;                                   //头插法第二步
    p = NULL;
    return path;                                //返回路径头部
}

//2.复制路径与路径集合

//2.1复制一条路径
Path CopyPath(Path path)
{
    Path tempath;
    tempath = (Path)CopyBrothers((Brother)path);
    return tempath;
}

//2.2复制路径集合
PathsPointer CopyPaths(PathsPointer paths)
{
    PathsPointer copynode, lastnode, head = NULL;
    
    while(paths)    {
        copynode = (PathsPointer)malloc(sizeof(Paths));
        copynode->path = CopyPath(paths->path);             //复制一条路径
        copynode->next = NULL;

        if(head == NULL)    {                               //首元路径
            head = copynode;
        } else  {                                           //其他路径
            lastnode->next = copynode;
        }
        lastnode = copynode;                                //加入路径集合
        paths = paths->next;
    }

    free(copynode);
    copynode = NULL;

    return paths;
}

//3.路径倒序与显示

//3.1路径倒序
void RevPath(Path path)
{
    int num = 0, i;
    Node *nodes = NULL;                                //节点集
    Path p = path;                              //路径

    while(p)    {                               //统计路径条数
        p = p->next;
        num++;
    }
    

    nodes = (Node *) malloc(num*sizeof(Node));
    
    for (i = 0, p = path; p; p = p->next, i++) //读取路径节点置于数组中
        SetValue(nodes[i], p->node);
    for (i = num - 1, p = path; p; p = p->next, i--) //数组数据倒序置于路径中
        SetValue(p->node, nodes[i]);

    free(nodes);                                //释放路径集
    nodes = NULL;
}


//3.2显示路径
void priPath(Path path)
{
    priBrothers((Brother)path);
}


//4.路径加入路径集合
PathsPointer AddPathToPaths(Path path, PathsPointer paths)
{
    Path copypath;
    PathsPointer ps = NULL, p;

    if(path == NULL)                                //路径不存在，直接返回
        return paths;

    copypath = CopyPath(path);                      //路径存在则copy
    ps = (PathsPointer)malloc(sizeof(Paths));
    ps->path = copypath;
    ps->next = NULL;
    if(paths == NULL)   {                           //第一条路径
        paths = ps;
    } else  {                                       //之后的路径
        p = paths;                                  //遍历，尾插法
        while(p)
            p = p->next;
        p->next = p;
    }

    free(copypath);
    free(ps);
    copypath = NULL;
    ps = NULL;

    return paths;                                   //返回路径集合
}

//5.节点集合与路径集合形成路径集合
PathsPointer FormPathsFromNodes(Brother brothers, Path path, PathsPointer paths)
{
    Path tempath;                                           //暂时存储路径
    while(brothers) {                                       //节点集不空
        tempath = CopyPath(path);                           //复制路径
        tempath = AddNodeToPath(brothers->node, tempath);   //将节点加入路径
        paths = AddPathToPaths(tempath, paths);             //将新路径加入路径集合
        brothers = brothers->next;                          //下一个节点
    }

    free(tempath);
    tempath = NULL;

    return paths;                                           //返回更新后的路径
}

//6.回收路径与路径集合空间

//6.1回收路径空间
Path ClearPath(Path path)
{
    path = (Path)ClearBrothers((Brother)path);
    return path;
}

//6.2回收路径集合空间
PathsPointer ClearPaths(PathsPointer paths)
{
    PathsPointer paths1 = paths;            //暂时存放路径集合
    while(paths)    {                       //路径集合不空
        paths1 = paths;                     //指向相同空间
        ClearPath(paths1->path);            //释放路径集合
        paths = paths->next;                //下一条路径
        free(paths1);                       //释放指针
        paths1 = NULL;
    }

    return paths;                           //返回NULL
}

//判断节点end是否在树中
Status DepthSearch(Tree tree, Node end);

//1.定位子树位置
Tree GetSubTree(Tree tree, Node pa);


/* 
//2.基于递归搜索子树
Status SearchSubTree(Tree tree, Tree subtree, Node end);

//3.搜索树
Status Search(Tree tree, Node start, Node end);
 */


//1.定位子树位置
Tree GetSubTree(Tree tree, Node pa)
{
    Tree subtree = tree;
    while(subtree)  {                           //遍历
        if(Equal(subtree->node.node, pa, EqualFun) == 0)
            break;                              //找到子树退出
        else    {
            subtree = subtree->next;
        }
    }

    return subtree;                             //返回子树
}

/*
//2.基于递归搜索子树
Status SearchSubTree(Tree tree, Tree subtree, Node end)
{
    Tree subsubtree;                                        //子树的子树
    Brother children;                                       //所有子节点
    Status flag = FALSE;                                    //存在标记
    
    if(subtree == NULL)
        return flag;
    
    
    //先序遍历，从根开始搜索
    if(Equal(subtree->node.node, end, EqualFun) == 0)   {   //子树的根节点是被搜索节点
        flag = TRUE;
    } else  {                                               //子根不是
        children = subtree->node.children;
        
        while(children) {                                   //深度优先搜索
            subsubtree = GetSubTree(tree, children->node);  //获得子树
            flag = SearchSubTree(tree, subsubtree, end);    //搜索子树
            if(flag == TRUE)
                break;
            children = children->next;
        }
    }

    return flag;
}

//3.搜索树
Status Search(Tree tree, Node start, Node end)
{
    Tree subtree;
    Status flag = FALSE;
    subtree = GetSubTree(tree, start);
    if(subtree) {
        flag = SearchSubTree(tree, subtree, end);
    } 
    
    return flag;
} 

 int main(int argc, char* argv[])
{
    Tree tree = NULL;
    Node start, end;
    Status flag = FALSE;
    char *filename = "ceshi.txt";
    tree = CreateTree(tree, filename);

    printf("==================\n");
    printf("The Start Node:");
    scanf("%s", start);
    printf("The End Node:");
    scanf("%s", end);

    flag = Search(tree, start, end);
    printf("Search %s from %s, Status = %d\n", end, start, flag);

    if(flag == TRUE)    {
        printf("\n Success!\n");
    } else {
        printf("\n Failed!\n");
    }
    printf("==================\n");

    ClearTree(tree);

    return 0;
} 

*/
//基于递归搜索路径

//1.基于递归搜索子树路径
Status SearchSubTree(Tree tree, Tree subtree, Node end, Path *path)
{
    Tree subsubtree;
    Brother children;
    Status flag = FALSE;
    
    if(!subtree)    {
        *path = NULL;
        return flag;
    }

    if(Equal(subtree->node.node, end, EqualFun) == 0)   {
        flag = TRUE;
        *path = AddNodeToPath(subtree->node.node, *path);
    } else  {
        children = subtree->node.children;
        
        while(children) {
            subsubtree = GetSubTree(subtree, children->node);
            flag = SearchSubTree(subtree, subsubtree, end, path);
            if(flag == TRUE)    {
                *path = AddNodeToPath(subtree->node.node, *path);
                break;
            }
            children = children->next;
        }
    }

    return flag;
}


//2基于递归的完整路径求解--深度优先搜索
Status SearchPath(Tree tree, Node start, Node end, Path *path)
{
    Tree subtree;
    Status flag = FALSE;
    subtree = GetSubTree(tree, start);
    if(subtree)
        flag = SearchSubTree(tree, subtree, end, path);
    
    return flag;
}
int main(int argc, char* argv[])
{
    Tree tree = NULL;
    Node start, end;
    Path path = NULL;
    Status flag = FALSE;
    char *filename = "...\\ceshi.txt";
    tree = CreateTree(tree, filename);
    printf("====================\n");
    printf("The Start Node:");
    scanf("%s", start);
    printf("The End Node:");
    scanf("%s", end);
    flag = SearchPath(tree, start, end, &path);
    printf("Search %s from %s, Status = %d\n", end, start, flag);
    printf("Path = ");
    //创建路径时采用了头插法，不需要逆序，原来的路径就是正序。
    //RevPath(path);
    //RevPath(path);
    priPath(path);
    printf("\n====================\n");
    ClearPath(path);
    ClearTree(tree);

    return 0;
}