
//COMPILE WITH -std=c++11
#include <iostream>
#include <math.h>
#include <stack>
#include <string>



using namespace std;


string calc(string infix);
bool isOperand(string value);
bool isOperator(string value);
double tempOp(double a, double b, string op);

int main(){
    string infix;
    cout<< "\n";
    cout << "Welcome to calculator"<< endl;
    cout << "Please enter your function"<< endl;
    cout << "\n";
    getline(cin, infix);
    //infix.erase(remove (infix.begin(), infix.end(), ' '), infix.end());
    
    cout<< "\n";
    string answer = calc(infix);
    cout << infix <<" = " << answer << endl;

}

//function that calculates your equation
string calc(string infix){
    string tempNum;
    string test;
    string test2;
    string test3;
    string test4;
    string test5;
    int rp = 0;
    int lp = 0;
    string num1 = "";
    string operation;
    string num2 = "";
    string cosNum = "";
    string str = "";
    string nums = "";
    string numsO = "";
    string par = "";
    stack<string> calcS;

     for(int i=0 ,j = infix.size(); i<j; i++){
        test = infix[i];
        if (test == "("){
            lp += 1;

        }

        else if (test == ")"){
            rp += 1;
        }

     }

     if (rp != lp){
        cout << "ERROR: UNBALANCED PARENTHESES" << endl;
        exit(0);
     }

    for(int i=0 ,j = infix.size(); i<j; i++){
         test = infix[i];
         test2 = infix [i+1];
         test3 = infix[i+2];
         test4 = infix[i+3]; 
         test5 = infix[i+4];
         
        //skips spaces
        if (test == " "){
            continue;
        } 

        else if (test == "("){
            
            
            if ((isOperand(test2) || test2 == ".") && ((!calcS.empty() && calcS.top() == "sin") || (!calcS.empty() && calcS.top() == "cos") || (!calcS.empty() && calcS.top() == "sqrt") ||(!calcS.empty() && calcS.top() == "log") ) ) {
                calcS.push(test);
                calcS.push("0");
                calcS.push("+");
                
                
            }
            
            else {
                calcS.push(test);
            
            }
            
        } 


        //checks for sin
        else if (test == "c" && test2 == "o" && test3 == "s" && test4 == "(") {
            
            calcS.push("cos");
            
               
        }
        //check for sin.... same for log and sqrt below VVV
        else if (test == "s" && test2 == "i" && test3 == "n" && test4 == "(") {
            calcS.push("sin");
        
        }

        else if (test == "l" && test2 == "o" && test3 == "g" && test4 == "(") {
            
            calcS.push("log");
        }    

        else if (test == "s" && test2 == "q" && test3 == "r" && test4 == "t" && test5 == "("){
            calcS.push("sqrt");
        }
        else if  (test == "-"){
        
            if (calcS.top() ==  "("){
                
                calcS.push("0");
                
                calcS.push(test);
                
              
               
            }
            
            else{  
                calcS.push(test);
            }
            

         }

        else if(isOperator(test)){
            calcS.push(test);
    
            //test.clear();
        

        }

        //pushes in numbers and accounts for multi digit numbers and decimals as well
        else if (isOperand(test)){
            while(!isOperator(test) && test != ")" && test != "(" && test != "-" && test != "+"&& i<j ){
            nums = nums + test;
            i++;
            test = infix[i];
            
            }
    
            i--;
            calcS.push(nums);
            nums.clear();
            //test.clear();

        }
        //contigent if statement to handle decimals
         else if (test == "."){
            while(!isOperator(test) && test != ")" && test != "(" && test != "-" && test != "+"&& i<j ){
            nums = nums + test;
            i++;
            test = infix[i];
            
            }
    
            i--;
            calcS.push(nums);
            nums.clear();
            //test.clear();

        }

   

        //if a closing parentheses is identified, proceed to pop and perform operations until you reach an opening parentheses  
        else if (test == ")"){

            
            while (calcS.top() != "("){
           
                num1 = calcS.top();
                calcS.pop();
                

                operation = calcS.top();
                calcS.pop();
                

                num2 = calcS.top();
                calcS.pop();
                double number1 = stod(num1);
                double number2 = stod(num2);
                double number3 = tempOp(number1, number2, operation);
                
                tempNum = to_string(number3);
                
                if(calcS.top() != "("){
                    
                    calcS.push(tempNum);
                  
                }
        
            }
        

           
               
                calcS.pop();
                //checks for cosine function to perform an operation 
                if (!calcS.empty() && calcS.top() == "cos"){
                    
                    double cosNum = stod(tempNum);
                  
                    string result = to_string(cos(cosNum*(3.14159265/180)));
                    
                    calcS.pop();
                    calcS.push(result);
                    
                    continue;


                }
                //check for sin function to perform an operation
                else if (!calcS.empty() && calcS.top() == "sin"){
                    
                    double sinNum = stod(tempNum);
                    
                    string result = to_string(sin(sinNum*(3.14159265/180)));
                    
                    calcS.pop();
                    calcS.push(result);
                    
                    continue;


                }
                //checks for sqrt function to perform and operation
                else if (!calcS.empty() && calcS.top() == "sqrt"){
                    
                    double sqrtNum = stod(tempNum);
                    
                    if (sqrtNum < 0){
                        cout << "ERROR: Cannot take the square root of a negative number!!!" << endl;
                        exit(0);
                    }
                    string result = to_string(sqrt(sqrtNum));
                    
                    calcS.pop();
                    calcS.push(result);
                    
                    continue;

                }
                //checks for log function to perform an operation
                 else if (!calcS.empty() && calcS.top() == "log"){
                    
                    double logNum = stod(tempNum);
                    
                    if (logNum <= 0){
                        cout << "ERROR: Out of log domain!!!" << endl;
                        exit(0);
                    }
                    string result = to_string(log(logNum));
                    
                    calcS.pop();
                    calcS.push(result);
                    
                    continue;

                }
           
            calcS.push(tempNum);
            
        }

        
            
        

        
  
    }


        
    while (calcS.size() > 1){
       
        string tempNum;
        
        num1 = calcS.top();
        
        calcS.pop();
        
        operation = calcS.top();
        calcS.pop();
        num2 = calcS.top();
        calcS.pop();
        double number1 = stod(num1);
        double number2 = stod(num2);
        double number3 = tempOp(number1, number2, operation);
        tempNum = to_string(number3);
        calcS.push(tempNum);
        operation.clear();
        num1.clear();
        num2.clear();
        
    }
    
    
    return calcS.top();
    
    

}
//performs an operation and returns a value to be either pushed into the stack 
//or to perform a complex operation (sin, cos, log, sqrt) if available
double tempOp(double a, double b, string op){
    double c;
if(op == "+"){
    c = a + b;
}

if (op == "-"){
    
    c = b - a;
}

if(op == "*"){
    c = a * b;
}

if (op == "/"){
    if (a == 0){
        cout<< "ERROR: division by 0!"<< endl;
        exit(0);
    }
    
    c = b/a;
}

if (op == "^"){
    
    c = pow(b,a);
}

return c;
}

//function that identifies calcS
bool isOperator(string value){
    
   
        if(value ==  "+"){
            return true;
            
        }

       else if(value ==  "-"){
            return true;
            
        }

        else if(value ==  "*"){
            return true;
            
        }

        else if(value ==  "/"){
            return true;
            
        }

        else if(value ==  "^"){
            return true;
            
        }

        else if(value ==  "+"){
            return true;
            
        }

        else 
            return false;
        
}

//function that identifies operands
bool isOperand(string value){

        if(value ==  "0"){
            return true;
            
        }

        else if(value ==  "1"){
            return true;
            
        }

        else if(value ==  "2"){
            return true;
            
        }

        else if(value ==  "3"){
            return true;
            
        }

        else if(value ==  "4"){
            return true;
            
        }

        else if(value ==  "5"){
            return true;
            
        }

        else if(value ==  "6"){
            return true;
            
        }

        else if(value ==  "7"){
            return true;
            
        }

        else if(value ==  "8"){
            return true;
            
        }

        else if(value ==  "9"){
            return true;
            
        }

        else 
            return false;

    
} 







  
  


    
    
    

