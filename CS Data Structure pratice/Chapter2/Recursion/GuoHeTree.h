#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <F:\VS_code_C\Books of YanWeimin\01xulun\Status.h>

#define EqualFun strcmp
#define SetValue strcpy
#define NAMESIZE 3

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