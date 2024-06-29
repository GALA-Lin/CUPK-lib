/*********************************************************************
程序名：更多练习 
版权：遵从GPL版权协议，可自由使用和传播（请勿上传到收费性网络文库）
作者：anbangli@foxmail.com
日期：2019-08-09
说明：
 
prog1-5.学习编程时不能满足于试验教材上的示例，至少应该试着做些修改，通过
编译和运行，检查加工中产生的信息，或查看运行情况，以进一步理解程序的意义。
例如，对1.4节的程序示例：
1. 把其中的第一行（“#include <iostream>”）改为注释，看看编译时会出现什么
信息？（请设法阅读理解系统产生的英文信息！）
2. 把程序中的第二行（“using namespace std;”）改为注释，看看编译时会出现
什么信息？
3. 把原来成对的花括号中删除一个，或者删除语句末尾的分号，试试编译。
4. 把英文的分号改为中文分号，或把（第一个或第二个）英文引号改为中文引号。
5. 切换到中文输入法，把输入提示条上的“  ”符号（半角）改为“  ”（全角），
在原有空格处输入几个空格（全角空格！）或英文字符（全角英文字符！），检查
编译情况——有时候我们不小心按了“Shift+空格”而改到全角状态，就可能出现
上述情况。
6. 把“cout << ”语句移动到“return 0;”语句之后，检查运行的情况。

多做些上面这一类练习，认真检查系统的反应（以及程序的输出），并动脑筋思考，
有可能得到书上没有提及、老师也没有讲到的细节经验。
*********************************************************************/

#include <iostream>

//1.若把“#include <iostream>”改为注释，则编译时会出现错误信息（英文和中译文）： 
//[Error] 'cout' was not declared in this scope [错误] 'cout' 在此范围内没有被声明
//[Error] 'endl' was not declared in this scope [错误] 'endl' 在此范围内没有被声明

using namespace std;
//2.若把“using namespace std;”改为注释，则编译时会出现大量的信息，其中红色显示、
//含有 "[Error]" 的是错误信息（下面是英文原文和中译文）： 
//[Error] 'cout' was not declared in this scope [错误] 'cout' 在此范围内没有被声明
//[Error] 'endl' was not declared in this scope [错误] 'endl' 在此范围内没有被声明
//其中含有 [Note] 的是相应的注解或建议：
// [Note] suggested alternative:  [注解] 建议可供替代的选择:  
// [Note] 'std::cout'             [注解] 可替代写为 'std::cout' 
// [Note] 'std::endl'             [注解] 可替代写为 'std::endl' 

int main() {
//3. 如果删除 main() 后面的左花括号，则编译时会出现如下错误信息：
//[Error] expected initializer before 'cout'       [错误]在 'cout' 之前期待初始化程序
//[Error] expected unqualified-id before 'return'  [错误] 在'return'之前期待不合格标识符
//[Error] expected declaration before '}' token    [错误] 在 '}' 令牌之前期待声明
	cout << "Hello, world!" << endl;
	
	cout << "Hello, Tome and Jerry!" << endl;
	
	cout << "I came from China, I'm Chinese." << endl;
	
	cout << "床前明月光，疑是地上霜。" << endl;
	//cout << "床前明月光，疑是地上霜。“ << endl;	//第二个英文引号改为中文引号
//4. 若把上面第二个英文引号改为中文引号，则编译时会出现如下信息： 
//[Warning] missing terminating " character    [警告]缺少终止的 " 字符
//[Error] missing terminating " character      [错误]缺少终止的 " 字符

	cout << "举头望明月，低头思故乡。" << endl;
	//cout <<　　"举头望明月，低头思故乡。" << endl;	//含有全角空格 
//5. 如果行内含有全角空格，则编译时会出现多个如下错误：
//[Error] stray '\241' in program          [错误]在程序中有杂散字符'\241' 


	return 0;
//3. 如果删除 "return 0" 后面的分号，则编译时会出现如下错误信息：
//[Error] expected ';' before '}' token    [错误] 在'}' 令牌之前期待';'  

	cout << "两个黄鹂鸣翠柳，一行白鹭上青天。" << endl;
	cout << "窗含西岭千秋雪，门泊东吴万里船。" << endl;
//6. 把“cout << ”语句移动到“return 0;”语句之后，则运行时并不会执行这两句， 
//即屏幕上并不会输出这些字符串。 

}
//3. 如果删除最末尾的右花括号，则编译时会出现如下错误信息：
//[Error] expected '}' at end of input        [错误] 在输入结束时期待 '}'


