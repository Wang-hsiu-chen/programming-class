//修 程式
#include<iostream>
#include<cmath>
#include<stack>
#include<string>
using namespace std;

double dealnumdot (string s , int first ) ; // 把一個整數或小數傳回來 
double siminput (string s , int first ) ; //單純數字輸入 
double dotinput(string s , int first ) ; //遇到忽略零輸入的小數時像是.1要等於0.1
double sininput (string s , int first ) ; //sin(a)
double cosinput (string s , int first ) ; //cos(a)
double taninput (string s , int first ) ; //tan(a)
double logtwoinput (string s , int first ) ; //log_{a}(b)
double logoneinput (string s , int first ) ; //log(a)
double sqrtinput (string s , int first ) ; //sqrt(a)
double evaluate(string s , int first ) ; //主要的 遇到括號會重複呼叫 

int parentCnt = 0 ; //紀錄()次數 
int bracketCnt = 0 ; //紀錄{}次數 
int parentNowI = 0; //幫忙指向已經完成的位置i 
int howLongSkip = 0 ; //配合siminput和dotinput在輸入時跳過幾個數字 

class Expression
{
	public :
	string s ;
	void input();
	void eval();
};
void Expression :: input()
{
	getline(cin,this->s);
}
void Expression :: eval()
{
	// 用函式的方式 利用遞迴和evaluate處理括號
	cout << evaluate(this->s,0) << endl;
}
int main()
{	
	Expression exp1;
	exp1.input();
	exp1.eval();
	return 0;
}

double evaluate(string s , int first )
{
	int nowlvl = 0 ;
	int nowopr = 0 ;
	/*
	我用了三個stack來記錄這些東西
	opd -> operand
	opr -> operator
	lvl -> level (priority) 
	operand裡面就是存數字的
	operator其實可以存char 不過我覺得存int比較習慣 所以我就把五種operand都編號了
	priority 是 加減存1 乘除存2 平方存三
	詳細的做法可以看下面這篇文章
	http://squall.cs.ntou.edu.tw/cpp/90Spring/SimpleCalculatorV1.html
	*/
	/*
	另外比較麻煩的地方應該算是括號，我是設定在看到左括號，就再重新呼叫一次這個函數
	並把左括號次數加一，等到遇到右括號再把他扣掉
	*/ 
	stack<double> opd ;
	stack<int> opr ; //1+ 2- 3* 4/ 5^
	stack<int> lvl ; // 1+- 2*/ 3^
	for ( int i = first ; i < s.size() ; i++ )
	{
		if(s[i]=='('||s[i]=='{')
		{
			if(s[i]=='(')
			{
				parentCnt ++ ;
				opd.push(evaluate( s , i+1 ));
				i=parentNowI ;
			}
			else
			{
				bracketCnt ++ ;
				opd.push(evaluate( s , i+1 ));
				i=parentNowI ;
			}
		}
		else if (s[i]=='-'&&(i==0||s[i-1]=='('))//處理負數 
		{
			opd.push(-siminput(s,i+1));
			i+=howLongSkip+1;
			howLongSkip = 0;
		}
		else if (isdigit(s[i]))
		{
			opd.push(siminput(s,i));
			i += howLongSkip ;
			howLongSkip = 0 ;
		}
		else if (s[i]=='.')//.23=0.23
		{
			opd.push(dotinput(s,i));
			i+=howLongSkip ;
			howLongSkip = 0 ;
		}
		else if (s[i]=='s'&&s[i+1]=='i') //sin(a)
		{
			opd.push(sininput(s,i+3));
			i=parentNowI ;
		}
		else if (s[i]=='c') //cos(a)
		{
			opd.push(cosinput(s,i+3));
			i=parentNowI ;
		}
		else if (s[i]=='t') //tan(a)
		{
			opd.push(taninput(s,i+3));
			i=parentNowI ;
		}
		else if (s[i]=='l'&&s[i+3]=='_') //log_{a}(b) 
		{
			opd.push(logtwoinput(s,i+4));
			i=parentNowI ;
		}
		else if (s[i]=='l') //log(a)
		{
			opd.push(logoneinput(s,i+3));
			i=parentNowI ;
		}
		else if (s[i]=='s'&&s[i+1]=='q') //sqrt(a)
		{		
			opd.push(sqrtinput(s,i+4));
			i=parentNowI ;
		}
		else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^') //確認加減乘除平方 
			{
				if (s[i] == '+')
				{
					opr.push(1);
					lvl.push(1);
				}
				else if ( s[i] == '-')
				{
					opr.push(2);
					lvl.push(1);
				}
				else if ( s[i] == '*')
				{
					opr.push(3);
					lvl.push(2);
				}
				else if ( s[i] == '/')
				{
					opr.push(4);
					lvl.push(2);
				}
				else if ( s[i] == '^')
				{
					opr.push(5);
					lvl.push(3);
				}
				while(!opr.empty() && opr.size()>1 && lvl.top()<=nowlvl ) //看看有沒有等級相同或更小，如果有就處理掉 
				{
					double temp = 0 ;
					if (nowopr == 1 )
					{
						temp = opd.top();
						opd.pop() ;
						temp = temp + opd.top();
						opd.pop() ;
						opd.push(temp);
					}
					else if (nowopr == 2 )
					{
						temp = opd.top();
						opd.pop() ;
						temp = opd.top() - temp ;
						opd.pop() ;
						opd.push(temp);
					}
					else if (nowopr == 3 )
					{
						temp = opd.top();
						opd.pop() ;
						temp = temp * opd.top();
						opd.pop() ;
						opd.push(temp);
					}
					else if ( nowopr == 4 )
					{
						temp = opd.top();
						opd.pop() ;
						temp = opd.top() / temp ;
						opd.pop() ;
						opd.push(temp);
					}
					else if ( nowopr == 5 )
					{
						temp = opd.top();
						opd.pop() ;
						temp = pow(opd.top(),temp) ;
						opd.pop() ;
						opd.push(temp);
					} 
					int tempopr = opr.top();
					opr.pop();
					opr.pop();
					if (!opr.empty())
						nowopr = opr.top();
					opr.push(tempopr);
					int templvl = lvl.top();
					lvl.pop();
					lvl.pop();
					if (!lvl.empty())
						nowlvl = lvl.top();
					lvl.push(templvl);
				}
				nowopr = opr.top();
				nowlvl = lvl.top();
			}
		if(s[i]==')'&&parentCnt>0)
		{
			parentCnt--;
			while(opd.size()>1)
			{
				double temp = 0 ;
				if(opr.top()==1)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp + opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==2)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() - temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==3)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp * opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==4)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() / temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==5)
				{
					temp = opd.top();
					opd.pop() ;
					temp = pow(opd.top(),temp) ;
					opd.pop() ;
					opd.push(temp);
				}
				opr.pop();
			}
			parentNowI = i ;
			return opd.top();
		}
		if(s[i]=='}'&&bracketCnt>0)
		{
			bracketCnt--;
			while(opd.size()>1)
			{
				double temp = 0 ;
				if(opr.top()==1)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp + opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==2)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() - temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==3)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp * opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==4)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() / temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==5)
				{
					temp = opd.top();
					opd.pop() ;
					temp = pow(opd.top(),temp) ;
					opd.pop() ;
					opd.push(temp);
				}
				opr.pop();
			}
			parentNowI = i ;
			return opd.top();
		}
		if (i == s.size()-1)  //處理加總 無條件處理到沒有東西剩下來
		{
			while(opd.size()>1)
			{
				double temp = 0 ;
				if(opr.top()==1)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp + opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==2)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() - temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==3)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp * opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==4)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() / temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==5)
				{
					temp = opd.top();
					opd.pop() ;
					temp = pow(opd.top(),temp) ;
					opd.pop() ;
					opd.push(temp);
				}
				opr.pop();
			}
		}
	}
	return opd.top();
}
double siminput (string s , int first )//輸入數字 
{
	return dealnumdot(s,first) ;	
}
double sininput ( string s , int first )
{
	parentCnt++ ;
	double sinAns = evaluate(s,first);
	sinAns = sin(sinAns);
	return sinAns ;
}
double cosinput ( string s , int first )
{
	parentCnt++ ;
	double cosAns = evaluate(s,first);
	cosAns = cos(cosAns);
	return cosAns ;
}
double taninput ( string s , int first )
{
	parentCnt++ ;
	double tanAns = evaluate(s,first);
	tanAns = tan(tanAns);
	return tanAns ;
}
double logtwoinput (string s , int first )//log自訂底用換底處理 
{
	bracketCnt++ ;
	parentCnt++ ;
	double logbase = evaluate(s,first);
	double lognum = evaluate(s,parentNowI+1) ;
	double logAns = log(lognum)/log(logbase);
	return logAns; 
}
double logoneinput ( string s , int first )
{
	parentCnt++ ;
	double logAns = evaluate(s,first);
	logAns = log(logAns);
	return logAns ;
}
double sqrtinput ( string s , int first )
{
	parentCnt++ ;
	double sqrtAns = evaluate(s,first);
	sqrtAns = sqrt(sqrtAns);
	return sqrtAns ;
}
double dotinput ( string s , int first )
{
	int length = 0 ;
	for ( int i = first ; i < s.size() ; i++ )
	{
		if(isdigit(s[i])||s[i]=='.')
			length++ ;
		else if(!isdigit(s[i]))
			break ;
		if(i == s.size()-1)
			break;
	}
	double ans = 0 ;
	for( int i = first+1 ; i < first+length ; i++ )
		ans = ans + (s[i]-'0')*(1/(pow(10,(i-first))));
	howLongSkip = length-1 ;
	return ans ;
}
double dealnumdot ( string s , int first ) //會把數字處理好變成一個小數或是整數回傳 
{
	int length = 0 ;
	for ( int i = first ; i < s.size() ; i++ )
	{
		if(isdigit(s[i])||s[i]=='.')
			length++ ;
		else if(!isdigit(s[i]))
			break ;
		if(i == s.size()-1)
			break;
	}
	bool dot = false ;
	int dotnum = -1 ;
	for ( int i = first ; i < first+length ; i++ )
	{
		if (s[i]=='.')
		{
			dot = true ;
			dotnum = i ; 
			break ;
		}
	}
	double ans = 0 ;
	if (dot)
	{
		for(int i = first ; i < dotnum ; i++ )
			ans = ans + (s[i]-'0')*pow(10,(dotnum-i-1));
		for(int i = dotnum+1 ; i < first+length ; i++ )
			ans = ans + (s[i]-'0')*(1/(pow(10,(i-dotnum))));
	}
	else
	{
		for(int i = first ; i < first+length ; i++ )
			ans = ans + (s[i]-'0')*pow(10,(first+length-i-1));
	}
	howLongSkip = length-1 ;
	return ans ;
}
