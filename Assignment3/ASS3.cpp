//�� �{��
#include<iostream>
#include<cmath>
#include<stack>
#include<string>
using namespace std;

double dealnumdot  (string s , int first ) ; //��@�Ӿ�ƩΤp�ƶǦ^�� 
double siminput    (string s , int first ) ; //��¼Ʀr��J 
double dotinput    (string s , int first ) ; //�J�쩿���s��J���p�Ʈɹ��O.1�n����0.1
double sininput    (string s , int first ) ; //sin(a)
double cosinput    (string s , int first ) ; //cos(a)
double taninput    (string s , int first ) ; //tan(a)
double logtwoinput (string s , int first ) ; //log_{a}(b)
double logoneinput (string s , int first ) ; //log(a)
double sqrtinput   (string s , int first ) ; //sqrt(a)
double evaluate    (string s , int first ) ; //�D�n�� �J��A���|���ƩI�s 

int parentCnt   = 0 ; //����()���� 
int bracketCnt  = 0 ; //����{}���� 
int parentNowI  = 0 ; //�������V�w�g��������mi 
int howLongSkip = 0 ; //�t�Xsiminput�Mdotinput�b��J�ɸ��L�X�ӼƦr 

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
	// �Ψ禡���覡 �Q�λ��j�Mevaluate�B�z�A��
	cout << evaluate(this->s,0);
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
	�ڥΤF�T��stack�ӰO���o�ǪF��
	opd -> operand
	opr -> operator
	lvl -> level (priority)
	operand�̭��N�O�s�Ʀr�� 
	operator���i�H�schar ���L��ı�o�sint����ߺD �ҥH�ڴN�⤭��operand���s���F 
	priority �O �[��s1 �����s2 ����s�T
	�ԲӪ����k�i�H�ݤU���o�g�峹 
	http://squall.cs.ntou.edu.tw/cpp/90Spring/SimpleCalculatorV1.html 
	*/
	/* 
	�t�~����·Ъ��a�����Ӻ�O�A���A�ڬO�]�w�b�ݨ쥪�A���A�N�A���s�I�s�@���o�Ө�� 
	�ç⥪�A�����ƥ[�@�A����J��k�A���A��L���� 
	*/ 
	stack<double> opd ;
	stack<int> opr ; // 1+ 2- 3-negative 4* 5/ 6^
	stack<int> lvl ; // 1+- 2-negative 3*/ 4^
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
				i = parentNowI ;
			}
		}
		else if (isdigit(s[i]))
		{
			opd.push(siminput(s,i));
			i += howLongSkip ;
			howLongSkip = 0 ;
		}
		else if (s[i]=='.') //.23=0.23
		{
			opd.push(dotinput(s,i));
			i += howLongSkip ;
			howLongSkip = 0 ;
		}
		else if (s[i]=='s'&&s[i+1]=='i') //sin(a)
		{
			opd.push(sininput(s,i+3));
			i = parentNowI ;
		}
		else if (s[i]=='c') //cos(a)
		{
			opd.push(cosinput(s,i+3));
			i = parentNowI ;
		}
		else if (s[i]=='t') //tan(a)
		{
			opd.push(taninput(s,i+3));
			i = parentNowI ;
		}
		else if (s[i]=='l'&&s[i+3]=='_') //log_{a}(b) 
		{
			opd.push(logtwoinput(s,i+4));
			i = parentNowI ;
		}
		else if (s[i]=='l') //log(a)
		{
			opd.push(logoneinput(s,i+3));
			i = parentNowI ;
		}
		else if (s[i]=='s'&&s[i+1]=='q') //sqrt(a)
		{		
			opd.push(sqrtinput(s,i+4));
			i = parentNowI ;
		}
		else if (s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'||s[i]=='^') //�T�{�[������� 
			{
				if (s[i]=='+')
				{
					opr.push(1);
					lvl.push(1);
				}
				else if (s[i]=='-'&&(i==0||s[i-1]=='('||s[i-1]=='{'))
				{
					opr.push(3);
					lvl.push(2);
				}
				else if (s[i]=='-')
				{
					opr.push(2);
					lvl.push(1);
				}
				else if (s[i]=='*')
				{
					opr.push(4);
					lvl.push(3);
				}
				else if (s[i] =='/')
				{
					opr.push(5);
					lvl.push(3);
				}
				else if (s[i]=='^')
				{
					opr.push(6);
					lvl.push(4);
				}
				while(opr.size()>1&&lvl.top()<=nowlvl) //�ݬݦ��S�����ŬۦP�Χ�p�A�p�G���N�B�z�� 
				{
					double temp = 0 ;
					if (nowopr==1)
					{
						temp = opd.top();
						opd.pop() ;
						temp = temp + opd.top();
						opd.pop() ;
						opd.push(temp);
					}
					else if (nowopr==2)
					{
						temp = opd.top();
						opd.pop() ;
						temp = opd.top() - temp ;
						opd.pop() ;
						opd.push(temp);
					}
					else if (nowopr==3)
					{
						temp = opd.top();
						opd.pop();
						opd.push(-temp);
					}
					else if (nowopr==4)
					{
						temp = opd.top();
						opd.pop() ;
						temp = temp * opd.top();
						opd.pop() ;
						opd.push(temp);
					}
					else if (nowopr==5)
					{
						temp = opd.top();
						opd.pop() ;
						temp = opd.top() / temp ;
						opd.pop() ;
						opd.push(temp);
					}
					else if (nowopr==6)
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
			while(!opr.empty())
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
				else if (opr.top()==3)
				{
					temp = opd.top();
					opd.pop();
					opd.push(-temp);
				}
				else if(opr.top()==4)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp * opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==5)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() / temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==6)
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
			while(!opr.empty())
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
				else if (opr.top()==3)
				{
					temp = opd.top();
					opd.pop();
					opd.push(-temp);
				}
				else if(opr.top()==4)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp * opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==5)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() / temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==6)
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
		if (i == s.size()-1)  //�B�z�[�` �L����B�z��S���F��ѤU��
		{
			while(!opr.empty())
			{
				double temp = 0 ;
				if(opr.top()==1)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp + opd.top();
					opd.pop();
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
				else if (opr.top()==3)
				{
					temp = opd.top();
					opd.pop();
					opd.push(-temp);
				}
				else if(opr.top()==4)
				{
					temp = opd.top();
					opd.pop() ;
					temp = temp * opd.top();
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==5)
				{
					temp = opd.top();
					opd.pop() ;
					temp = opd.top() / temp ;
					opd.pop() ;
					opd.push(temp);
				}
				else if(opr.top()==6)
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
double siminput ( string s , int first )//��J�Ʀr 
{
	return dealnumdot(s,first) ;	
}
double sininput ( string s , int first )
{
	parentCnt ++ ;
	double sinAns = evaluate(s,first);
	sinAns = sin(sinAns);
	return sinAns ;
}
double cosinput ( string s , int first )
{
	parentCnt ++ ;
	double cosAns = evaluate(s,first);
	cosAns = cos(cosAns);
	return cosAns ;
}
double taninput ( string s , int first )
{
	parentCnt ++ ;
	double tanAns = evaluate(s,first);
	tanAns = tan(tanAns);
	return tanAns ;
}
double logtwoinput ( string s , int first )//log�ۭq���δ����B�z 
{
	bracketCnt ++ ;
	parentCnt ++ ;
	double logbase = evaluate(s,first);
	double lognum = evaluate(s,parentNowI+1) ;
	double logAns = log(lognum)/log(logbase);
	return logAns; 
}
double logoneinput ( string s , int first )
{
	parentCnt ++ ;
	double logAns = evaluate(s,first);
	logAns = log(logAns);
	return logAns ;
}
double sqrtinput ( string s , int first )
{
	parentCnt ++ ;
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
			length ++ ;
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
double dealnumdot ( string s , int first ) //�|��Ʀr�B�z�n�ܦ��@�Ӥp�ƩάO��Ʀ^�� 
{
	int length = 0 ;
	for ( int i = first ; i < s.size() ; i++ )
	{
		if(isdigit(s[i])||s[i]=='.')
			length ++ ;
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
