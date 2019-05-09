//存储图书信息
typedef struct book
{
	char num[10];//书号码
	char name[15];//书名
	int price;//价格
	char author[15];//作者
	char pub[20];//出版社
	int number;//数量
};

//会员信息
typedef struct Member
{
	char mnum[10];//会员号
	char mname[15];//会员姓名
	char tel[15];//会员手机号
};

typedef struct borrow
{
	char mnum[10];//会员号
	char mname[15];//会员姓名
	char num[10];//书号
	char name[15];//书名
};

//图书信息链表的结点结构
typedef struct node
{
	struct book data;
	struct node* next;
}	Node,*Link;

//定义会员信息的链表结点结构
typedef struct mnode
{
	struct Member inf;
	struct mnode *next;
}	Mnode,*Mlink;

//定义结束信息链表的结点结构
typedef struct bnode
{
	struct borrow binf;
	struct bnode* next;
}	Bnode,*Blink;

void MainMenu();
int Ide,Key;
Link I;
Mlink m;
Blink b;



