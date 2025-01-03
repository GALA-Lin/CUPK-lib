//AddAPathToPaths把一条路径加入到路径集中。原理上是队列加入数据元素操作。
struct Paths *AddAPathToPaths(Path path, struct Paths *Paths) //路径加入路径集合
{
    Path copypath;
    struct Paths *ps = NULL, *p;
    if (path == NULL) return Paths; //没有路径
    copypath = CopyPath(path); //复制路径
    ps = (struct Paths *) malloc(sizeof(struct Paths)); //开辟路径集合节点
    ps->path = copypath; //复制的路径置入
    ps->next = NULL;
    if (Paths == NULL)  //路径集合为空
        Paths = ps;
    else //新节点路径放置最后
    {
        p = Paths;
        while (p->next) p = p->next;
        p->next = ps;
    }
    return Paths;
}