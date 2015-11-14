#Algorithm-Exercise

## 算法分析与设计作业 实验4

### 题目说明
输入: 某无向图 整数M
输出: 是否能用M种颜色染色各个节点并可以保证每两个相邻节点颜色不同
要求：使用回溯法
### 思路
重用实验3的构造图代码，因此这次只写两个函数就能实现需要的功能，其中can_color()判断是否能着某色，color_all()为回溯函数。
划分的子问题为，对于当前节点，如果能着color色，就着该色，并尝试下一节点着1色，否则尝试该节点着color+1色。
### 使用说明
输入流重定向为"in.txt"
首先输入一个整数M，表示最多使用M种颜色来染色。
接着输入无向图的每个节点。
每个节点一行。
下面的输出样例图跟实验3基本相同
    5
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
    
会在"out.txt"中输出着色情况：
      
    用4种颜色不能染色
    着色情况如下：
    A => 1
    B => 2
    C => 1
    D => 3
    E => 1
    F => 4
    G => 1
    H => 3
    I => 4
    J => 1
    K => 2
    L => 0
