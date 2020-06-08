#include <iostream>
#include <fstream>
#include <algorithm>
#include <functional>
#include <string>
#include <set>
#include "��ɢ_��Ԫ��ϵ.h"
using namespace std;
//���������ࣺSET�����ϣ���ordinal_pair����ż��
//֧�ֵ��������ͣ�int,char,string,SET,ordinal_pair
//֧�ֲ�ͬ�������ݻ�ϴ���
//֧�ֵ����㣺����&&��������+�����-�����ԳƲSymmetrical_difference(SET 1,SET2)�����ݼ���SET.power()�����ѿ�������*��
//֧�������<<��������ֱ�ӽ������cout���

int main()
{

#if 1
	ifstream input1("input1");
	ifstream input2("input2");

	SET SET0 = {};
	cout << "SET0:" << SET0 << endl;

	SET SET1;
	if (input1)
	{
		input1 >> SET1;
		cout << "SET1:" << SET1 << endl;
	}
	else
		cout << "input1 open failed" << endl;

	ordinal_pair op1 = { 25, string("Hello,world!")};
	cout << "op1:" << op1 << endl;

	SET SET2;
	if (input2)
	{
		input2 >> SET2;
		SET2.push(op1);
		cout << "SET2:" << SET2 << endl;
	}
	else
		cout << "input2 open failed" << endl;

	input1.close();
	input2.close();

	SET SET3 = { 1, 3, 5, 7 };
	SET3.push({ 'H', 'l' });
	SET3.push(SET1);
	SET3.push(op1);
	cout << "SET3:" << SET3 << endl;

	SET SET4 = SET1 - SET3;
	cout << "SET4:" << SET4 << endl;

	SET SET5 = SET1 + SET3;
	cout << "SET5:" << SET5 << endl;

	SET SET6 = SET1 && SET3;
	cout << "SET6:" << SET6 << endl;

	SET SET7 = Symmetrical_difference(SET1, SET3);
	cout << "SET7:" << SET7 << endl;

	SET SET8 = SET4.power();
	cout << "SET8:" << SET8 << endl;

	SET SET9 = SET5 * SET6;
	cout << "SET9:" << SET9 << endl;

	cout << endl;

	SET::iterator its = SET5.begin(); //������
	++its;
	cout << *its << endl;
	for (Date T : SET5)
		cout << T << " ";
#endif // ������ʾ

#if 0
	ifstream input1("input1.txt");
	ifstream input2("input2.txt");
	ifstream input3("input3.txt");
	ifstream input4("input4.txt");
	ifstream input5("input5.txt");

	SET S1;
	SET S2;
	if (!input1)
		std::cout << "input1.txt open failed!" << endl;
	else
		input1 >> S1;
	if (!input2)
		std::cout << "input2.txt open failed!" << endl;
	else
		input2 >> S2;

	input1.close();
	input2.close();

	Binary_relationship BR1(S1);	 //S1�ϵĶ�Ԫ��ϵ
	Binary_relationship BR2(S1, S2); //S1��S2�Ķ�Ԫ��ϵ
	Binary_relationship BR3, BR4, BR5, BR6, BR7;
	SET SET8, SET9, SET10;
	BR3 = Binary_relationship::E(S1);		  //ȫ��
	BR4 = Binary_relationship::I(S1);		  //���
	BR5 = Binary_relationship::L(S1);		  //С�ڻ����
	BR6 = Binary_relationship::D(S2);		  //����
	BR7 = Binary_relationship::R(S1.power()); //����
	SET8 = Binary_relationship::domR(BR6);	  //������
	SET9 = Binary_relationship::ranR(BR6);	  //ֵ��
	SET10 = Binary_relationship::fldR(BR6);	  //����

	Binary_relationship BR11, BR12, BR13;

	if (!input3)
		std::cout << "input3.txt open failed!" << endl;
	else
	{
		ordinal_pair temp;
		while (input3 >> temp)
			BR11.push(temp);
		input3.close();
	}

	if (!input4)
		std::cout << "input4.txt open failed!" << endl;
	else
	{
		ordinal_pair temp;
		while (input4 >> temp)
			BR12.push(temp);
		input4.close();
	}

	if (!input5)
		std::cout << "input4.txt open failed!" << endl;
	else
	{
		ordinal_pair temp;
		while (input5 >> temp)
			BR13.push(temp);
		input5.close();
	}

	std::cout << "BR1:" << BR1 << endl
			  << "BR2:" << BR2 << endl
			  << endl
			  << "BR3:" << BR3 << endl
			  << endl
			  << "BR4:" << BR4 << endl
			  << endl
			  << "BR5:" << BR5 << endl
			  << endl
			  << "BR6:" << BR6 << endl
			  << endl
			  << "BR7:" << BR7 << endl
			  << endl
			  << "SET8:" << SET8 << endl
			  << endl
			  << "SET9:" << SET9 << endl
			  << endl
			  << "SET10:" << SET10 << endl
			  << endl
			  //�Է������Է�
			  << "BR11�Է��� " << BR11.Reflexive(S1) << endl
			  << endl
			  << "BR11���Է��� " << BR11.Anti_reflexive(S1) << endl
			  << endl
			  << "BR12�Է��� " << BR12.Reflexive(S1) << endl
			  << endl
			  << "BR12���Է��� " << BR12.Anti_reflexive(S1) << endl
			  << endl
			  << "BR13�Է��� " << BR13.Reflexive(S1) << endl
			  << endl
			  << "BR13���Է��� " << BR13.Anti_reflexive(S1) << endl
			  << endl
			  << "BR11�Գƣ� " << BR11.Symmetry(S1) << endl
			  << endl
			  << "BR11���Գƣ� " << BR11.Antisymmetric(S1) << endl
			  << endl
			  << "BR12�Գƣ� " << BR12.Symmetry(S1) << endl
			  << endl
			  << "BR12���Գƣ� " << BR12.Antisymmetric(S1) << endl
			  << endl
			  << "BR13�Գƣ� " << BR13.Symmetry(S1) << endl
			  << endl
			  << "BR13���Գƣ� " << BR13.Antisymmetric(S1) << endl
			  << endl;

#endif // ��Ԫ��ϵ��ʾ

	
	return 0;
}
