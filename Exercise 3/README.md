#Algorithm-Exercise

## 算法分析与设计作业 实验3

### 题目说明
输入: 某无向图
要求: 构造该图的最小划分

### 思路
先将所有节点及其邻接表存入MAP中，后生成按照节点度大小排列的向量列表，每次遍历该列表前生成新子集，遍历时，判断每个元素是否能加入到当前子集中。若能则加入，并从列表中删除该节点，直到列表为空。
### 使用说明
<<<<<<< HEAD
无向图的每个节点及其相连的节点输入到"[in.txt](https://github.com/pal6exe/Algorithm-Exercise/blob/master/Exercise%203/in.txt)"中
=======
无向图的每个节点及其相连的节点输入到"in.txt"中
>>>>>>> del
每个节点一行

    ABIHL
    BAHFDCL
    CBIHFDL
    DCBIFEL
    EDFL
    FGHBCDEL
    GHFL
    HABCFGL
    IABCDL
    JKL
    KJL
    LABCDEFGHIJK
    
<<<<<<< HEAD
![范例图](https://github.com/pal6exe/Algorithm-Exercise/raw/master/Exercise%203/G.png)

如上图↑

然后会在"[out.txt](https://github.com/pal6exe/Algorithm-Exercise/blob/master/Exercise%203/out.txt)"中依次输出该图的邻接表，按度从大到小的顺序排列的节点，最小子划分：
=======
其图如下 ![范例图](https://github.com/banixc/Algorithm-Exercise/raw/master/Exercise%203/G.png)
会在"out.txt"中依次输出该图的邻接表，按度从大到小的顺序排列的节点，和最小子划分：
>>>>>>> del
      
    您输入的图的节点邻接关系如下：
    A => B I H L 
    B => A H F D C L 
    C => B I H F D L 
    D => C B I F E L 
    E => D F L 
    F => G H B C D E L 
    G => H F L 
    H => A B C F G L 
    I => A B C D L 
    J => K L 
    K => J L 
    L => A B C D E F G H I J K 
    节点按度大小的排列：
    L => 11
    F => 7
    H => 6
    D => 6
    C => 6
    B => 6
    I => 5
    A => 4
    G => 3
    E => 3
    K => 2
    J => 2
    划分集合
    { L }
    { F I K }
    { H D J }
    { C A G E }
    { B }

    