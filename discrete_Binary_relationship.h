#pragma once
#include "��ɢ_������ҵ.h"
#include <algorithm>
#include <iostream>


class Binary_relationship
{
public:
	Binary_relationship();									//����
	Binary_relationship(initializer_list<ordinal_pair> op); //����ż�б��ʼ��
	void push(const ordinal_pair &op);						//���Ԫ��
	Binary_relationship(SET &S);							//S�Ķ�Ԫ��ϵ
	Binary_relationship(SET &S1, SET &S2);					//S1��S2�Ķ�Ԫ��ϵ
	static Binary_relationship E(SET &S);					//ȫ���ϵ
	static Binary_relationship I(const SET &S);				//��ȹ�ϵ
	static Binary_relationship L(const SET &S);				//С�ڻ���ڹ�ϵ
	static Binary_relationship D(const SET &S);				//������ϵ
	static Binary_relationship R(const SET &S);				//������ϵ
	static SET domR(const Binary_relationship &br);			//������
	static SET ranR(const Binary_relationship &br);			//ֵ��
	static SET fldR(const Binary_relationship &br);			//����
	bool Reflexive(const SET &S);							//s1�Է�
	bool Anti_reflexive(const SET &S);						//���Է�
	bool Symmetry(SET S);									//�Գ�
	bool Antisymmetric(SET S);								//���Գ�
	void Transfer(SET S) {};					//����

	~Binary_relationship(); //����

	friend ostream &operator<<(ostream &os, Binary_relationship &BR); //�����<<����

private:
	SET date;
};

Binary_relationship::Binary_relationship()
{
}

inline Binary_relationship::Binary_relationship(initializer_list<ordinal_pair> op)
{
	date.push(op);
}

inline void Binary_relationship::push(const ordinal_pair &op)
{
	date.push(op);
}

inline Binary_relationship::Binary_relationship(SET &S)
{
	date = S * S;
}

inline Binary_relationship Binary_relationship::E(SET &S)
{
	Binary_relationship Temp;
	Temp.date = S * S;
	return Temp;
}

inline Binary_relationship Binary_relationship::I(const SET &S)
{
	Binary_relationship temp;
	for (Date date : S.DATES)
		temp.date.push(ordinal_pair(date, date));
	/*for (char ch : S.CHS)
		temp.date.push(ordinal_pair(ch, ch));
	for (string s : S.STRS)
		temp.date.push(ordinal_pair(s, s));
	for (SET T : S.SETS)
		temp.date.push(ordinal_pair(T, T));
	for (ordinal_pair op : S.OPS)
		temp.date.push(ordinal_pair(op, op));*/
	return temp;
}

inline Binary_relationship Binary_relationship::L(const SET &S)
{
	Binary_relationship temp;
	/*if (S.CHS.size() > 0 || S.STRS.size() > 0 || S.SETS.size() > 0 || S.OPS.size() > 0 || S.IS.size() == 0)
		return Binary_relationship();*/

	for (Date i1 : S.DATES)
		for (Date i2 : S.DATES)
			if (i1 < i2 || i1 == i2)
				temp.date.push(ordinal_pair(i1, i2));
	return temp;
}

inline Binary_relationship Binary_relationship::D(const SET &S)
{
	Binary_relationship temp;
	/*if (S.CHS.size() > 0 || S.STRS.size() > 0 || S.SETS.size() > 0 || S.OPS.size() > 0 || S.IS.size() == 0)
		return Binary_relationship();*/
	for (Date i1 : S.DATES)
		for (Date i2 : S.DATES)
			if (i2 % i1 == 0)
				temp.date.push(ordinal_pair(i1, i2));
	return temp;
}

inline Binary_relationship Binary_relationship::R(const SET &S)
{
	Binary_relationship temp;
	/*if (S.CHS.size() > 0 || S.STRS.size() > 0 || S.OPS.size() > 0 || S.IS.size() > 0 || S.SETS.size() == 0)
		return Binary_relationship();*/
	
	for (Date T1 : S.DATES)
	{
		for (Date T2 : S.DATES)
		{
			if (T1.ty != Set || T2.ty != Set)
			{
				std::cout << "���зǼ���Ԫ�أ�" << endl;
				return Binary_relationship();
			}
			SET::iterator it3 = T2.SETT->begin();
			for (; it3 != T2.SETT->end(); ++it3)
			{
				if (T1.SETT->find(*it3)==T1.SETT->end())
					break;
			}
			if (it3 == T2.SETT->end())
				temp.date.push(ordinal_pair(T1, T2));
		}
	}
	return temp;
}

inline Binary_relationship::Binary_relationship(SET &S1, SET &S2)
{
	date = S1 * S2;
}

inline SET Binary_relationship::domR(const Binary_relationship &br)
{
	SET temp;
	for (Date T : br.date.DATES)
		temp.push(T.OP->date[0]);
	return temp;
}

inline SET Binary_relationship::ranR(const Binary_relationship &br)
{
	SET temp;
	for (Date T : br.date.DATES)
		temp.push(T.OP->date[1]);
	return temp;
}

inline SET Binary_relationship::fldR(const Binary_relationship &br)
{
	SET temp = domR(br) + ranR(br);
	return temp;
}

inline bool Binary_relationship::Reflexive(const SET &S)
{
	for (Date i : S.DATES)
		if (date.find(Date(ordinal_pair(i, i)))==date.end())
			return false;
	return true;
}

inline bool Binary_relationship::Anti_reflexive(const SET &S)
{
	for (Date i : S.DATES)
		if (date.find(Date(ordinal_pair(i, i))) != date.end())
			return false;
	return true;
}

inline bool Binary_relationship::Symmetry(SET S)
{
	Binary_relationship temp = E(S);
	for (Date op : date.DATES)
		if (temp.date.find(op)==temp.date.end() || date.find(Date(op.OP->anti()))==temp.date.end())
			return false;
	return true;
}

inline bool Binary_relationship::Antisymmetric(SET S)
{
	Binary_relationship temp = E(S);
	for (Date op : date.DATES)
	{
		if (temp.date.find(op)!=temp.date.end())
		{
			if (date.find(Date(op.OP->anti()))!=date.end() && !(*op.OP == op.OP->anti()))
				return false;
		}
		else
			return false;
	}
	return true;
}

inline Binary_relationship::~Binary_relationship()
{
}

ostream &operator<<(ostream &os, Binary_relationship &BR)
{
	os << BR.date;
	// TODO: �ڴ˴����� return ���
	return os;
}
