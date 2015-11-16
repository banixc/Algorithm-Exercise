#Algorithm-Exercise

## 算法分析与设计作业 实验1

### 题目说明
输入: 二叉树的前序遍历和中序遍历

要求: 构造该二叉树 

### 使用说明
将二叉树的前序遍历和中序遍历分别输入到"[in.txt](https://github.com/pal6exe/Algorithm-Exercise/blob/master/Exercise%201/in.txt)"中

每个遍历一行

	ABCDE
	EDCBA
	ABDECFG
	DBEAFCG
	ABDGEMCFN
	DGBMEAFNC
	
可连续输入多行

然后运行程序得到的结果输出在"[out.txt](https://github.com/pal6exe/Algorithm-Exercise/blob/master/Exercise%201/out.txt)"

	PreOrderInput:	ABCDE
	InOrderInput:	EDCBA
	PreOrder: 	ABCDE
	InOrder: 	EDCBA
	PostOrder: 	EDCBA

	PreOrderInput:	ABDECFG
	InOrderInput:	DBEAFCG
	PreOrder: 	ABDECFG
	InOrder: 	DBEAFCG
	PostOrder: 	DEBFGCA

	PreOrderInput:	ABDGEMCFN
	InOrderInput:	DGBMEAFNC
	PreOrder: 	ABDGEMCFN
	InOrder: 	DGBMEAFNC
	PostOrder: 	GDMEBNFCA
