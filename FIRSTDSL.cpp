#include<iostream>
using namespace std;

#define KEY(x) x%10

struct node
{
	string name,phnum;
	int key;
	node *next;
}*hash[10];

class Database
{
	public:
		int sum(string name)
		{int sum = 0;
		for (int i = 0;name[i]!='\0';i++)
			sum = sum + name[i];
		return sum;
		}
	
	node*create()
	{
		node *temp = new(struct node);
		cout<<"Enter the name :"<<endl;
		cin.ignore();
		getline(cin,temp->name);
		
		cout<<"Enter the phone number :"<<endl;
		getline(cin,temp->phnum);
		temp->next='\0';
		int z=sum(temp->name);
		temp->key = KEY(z);
		return temp;
	}
	
	void position(node *p,int key)
	{
		if(!hash[key])
		{
			hash[key]= p;
		}
		else{
			node*q;
			q=hash[key];
			while(q->next!='\0')
			q =q->next;
			q->next = p;
		}
	}
	
	void add()
	{
		node *p;
		p=create();
		position(p,p->key);
		while(p!=NULL)
		{
			cout<<p->name<<":"<<p->phnum<<""<<"\n";
			p=p->next;
		}
	}
	node* search(int key,string name)
	{
		node *p;
		p= hash[key];
		while((p!='\0')&&(name!=p->name))
			p=p->next;
		return p;
	}
};

int main(){
	Database obj;
	node n1;
	string a;
	int key,x;
	int ch;
	do
	{
		cout<<"\n===============HASH TABLE================"<<endl;
		cout<<"\n1.Add a Entry in hash table"<<endl;
		cout<<"\n2. Search a number"<<endl;
		cout<<"\nEnter your choice :"<<endl;
		cout<<"============================================"<<endl;
		
		cin>>ch;
		switch(ch)
		{
			case 1:
				{
					do
					{
						obj.add();
						cout<<"Do you want to add more Entries >(1.Yes, 2.No)"<<endl;
						cin>>x;
					}
					while(x==1);
					break;
				}
			case 2:
				{
					cout<<"Enter the name of the person: "<<endl;
					cin.ignore();
					getline(cin,a);
					int z = obj.sum(a);
					key = KEY(z);
					node *p;
					p = obj.search(key,a);
					if (!p)
					{
						cout<<"No such entry in Database"<<endl;
					}
					else{
						cout<<"Name :"<<p->name<<endl;
						cout<<"Phone Number :"<<p->phnum<<endl;
					}
				break;
				}
			default:cout<<"Invalid Entry"<<endl;
			break;
		 }
		 cout<<"Do you want to continue?(1.Yes, 2.No)"<<endl;
		 cin>>x;
	}while(x==1);
	
	return 0;
}
