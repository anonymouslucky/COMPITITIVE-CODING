#include<bits/stdc++.h>
#define lli long long int
#define pb push_back
#define INF 1e12
#define N 100010
#define tol 1e-12
#define P pair
#define mk make_pair
#define rep(i,lower,upper) for(i=lower;i<=upper;i++)
#define repr(i,upper,lower) for(i=upper;i>=lower;i--)
 
using namespace std;

string str;

struct Node
{
	char ch;
	map<char,Node*> children;
	bool done;
};

class Trie
{
public:
	Trie(){head.ch = -1;};
	~Trie();
	void insert(string word);
	Node head;
	vector<Node*> children;
	bool search();
};

Trie::~Trie()
{
	lli i;
	for(i=0;i<children.size();i++)
		delete children[i];
}


void Trie::insert(string word)
{
	map<char , Node*> *current_tree = &head.children;
	map<char , Node*>::iterator it;
	Node *curr = &head;
	lli i;
	char c;
	for(i=0;i<word.length();i++)
	{
		c = word[i];
		if((it=current_tree->find(c)) != current_tree->end())
		{
			current_tree = &it->second->children;
			curr = it->second;
		}
		else
		{
			Node *new_node = new Node();
			new_node->ch = c;
			new_node->done = 0;
			(*current_tree)[c] = new_node;

			current_tree = &new_node->children;
			curr = new_node;
		}
	}
	curr->done = 1;
}

bool dfs(Node *curr,lli index,bool used)
{
	lli n = str.length();
	if(index == n)
	{
		if(!used)
			return 0;
		return curr->done;
	}
	
	map<char , Node*> *current_tree = &curr->children;
	map<char , Node*>::iterator it;
	bool valid = 0;
	if(used)
	{
		if((it = current_tree->find(str[index])) != current_tree->end())
		{
			return dfs(it->second,index+1,used);
		}
		else
			return 0;
	}
	
	for(it=current_tree->begin();it!=current_tree->end();it++)
	{
		if(it->first == str[index])
			valid = dfs(it->second,index+1,used);
		else
			valid = dfs(it->second,index+1,!used);
		
		if(valid)
			return valid;
	}
	return 0;
}

bool Trie::search()
{
	Node *curr = &head;
	return dfs(curr,0,0);
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	lli n,m,i,j,k;
	cin>>n>>m;
	string s;
	
	Trie trie;
	rep(i,1,n)
	{
		cin>>s;
		trie.insert(s);
	}
	
	while(m--)
	{
		cin>>str;
		if(trie.search())
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
}
