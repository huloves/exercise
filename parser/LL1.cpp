#include<iostream>
#include<vector>
#include<string>
#include<stack>

#define BEGIN_SYB 'E'

class Tab {                   //预测分析表中单个产生式
public:
    Tab(char n,char e,std::string p):noend(n),end(e),prod(p) {};

    char noend;
    char end;
    std::string prod;
};

std::vector<Tab>  pTab;       //预测分析表
std::stack<char>  pStack;     //栈
std::string       pStr;       //输入串
int               index = 0;  //输入串的下标
int               num = 0;    //下标
char              X;          //从栈顶取出的符号
char              a;          //字符串目前分析到的位置
std::vector<char> VT{'i','+','*','(',')','#'};    //终结符号集合
std::vector<char> VN{'E','Z','T','Y','F'};    //非终结符号集合

int
isPartVT(char ch)
{
    for(auto u:VT) {
        if(u == ch) {
            return 1;
        }
    }
    return 0;
}

int
isPartVN(char ch)
{
    for(auto u:VN) {
        if(u == ch) {
            return 1;
        }
    }
    return 0;
}

void
initpTab()
{
    pTab.push_back(Tab('E','i',"TZ"));       //Z表示E'
    pTab.push_back(Tab('E','(',"TZ"));
    pTab.push_back(Tab('Z','+',"+TZ"));
    pTab.push_back(Tab('Z',')',"$"));
    pTab.push_back(Tab('Z','#',"$"));
    pTab.push_back(Tab('T','i',"FY"));
    pTab.push_back(Tab('T','(',"FY"));       //Y表示T'
    pTab.push_back(Tab('Y','+',"$"));
    pTab.push_back(Tab('Y','*',"*FY"));
    pTab.push_back(Tab('Y',')',"$"));
    pTab.push_back(Tab('Y','#',"$"));
    pTab.push_back(Tab('F','i',"i"));
    pTab.push_back(Tab('F','(',"(E)"));
}

void 
printStack()
{
    std::stack<char> pTemp(pStack);
    while(pTemp.size() != 0) {
        std::cout << pTemp.top() << " ";
        pTemp.pop();
    }
    std::cout << "         ";
}

int
synaly()
{
    pStack.push(pStr[index++]);
    pStack.push(BEGIN_SYB);
    a = pStr[index++];
    bool flag = true;
    while(flag) {
        std::cout << num++ << "        ";  //输出行号
        printStack();
        if(pStack.size() != 0) {
            X = pStack.top();              //将符号栈顶给X
            pStack.pop();
        }

        if(isPartVT(X)) {                  //如果是终结符
            if(X == '#' && a == '#') {
                flag = false;
            }else if(X == a){
                std::cout << std::endl;
                a = pStr[index++];
            }else {
                std::cout << "EROOR!" << std::endl;
                return 0;
            }

        }else if (X == '#') {
            if(X == a) {
                flag = false;
            }else {
                std::cout << "EROOR!" << std::endl;
                return 0;
            }

        }else if (isPartVN(X) && isPartVT(a)) {  //如果非终结符
            int type = 0;
            for(auto u:pTab) {
                if(u.noend == X && u.end == a) {
                    std::string tempProd = u.prod;
                    std::cout << X << "->" << tempProd << std::endl; 
                    if(tempProd == "$") {
                        type = 1;
                        break;
                    }else {
                        for(int i = tempProd.size()-1;i >= 0;--i) {
                            pStack.push(tempProd[i]);
                        }
                        type = 1;
                        break;
                    }
                }
            }
            if(type != 1) {
                std::cout << "EROOR!" << std::endl;
                return 0;

            }

        }else {
            std::cout << "EROOR!" << std::endl;
            return 0;
        }

    }
    return 1;
}

int main(int argc,char *argv[])
{
    initpTab();
    std::cout << "请输入语法串:";
    std::cin >> pStr;
    std::cout << "步骤" << "     " << "符号栈" << "      " << "所用产生式" << std::endl;
    int flag = synaly();
    std::cout << std::endl;
    if(flag == 1) {
        std::cout << "分析成功~~" << std::endl;
    }else {
        std::cout << "分析失败~~" << std::endl;
    }

    return 0;
}
