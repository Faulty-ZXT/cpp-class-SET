#pragma once
#include "��ɢ_������ҵ.h"
#include<iostream>



class Binary_relationship
{
public:
	Binary_relationship();
	Binary_relationship(SET &S);//S�Ķ�Ԫ��ϵ
	Binary_relationship(SET &S1, SET &S2);//S1��S2�Ķ�Ԫ��ϵ
	static Binary_relationship E(SET &S);//ȫ���ϵ
	static Binary_relationship I(const SET &S);//��ȹ�ϵ
	static Binary_relationship L(const SET &S);//С�ڻ���ڹ�ϵ
	static Binary_relationship D(const SET &S);//������ϵ
	static Binary_relationship R(const SET &S);//������ϵ
	static SET domR(const Binary_relationship &br);//������
	static SET ranR(const Binary_relationship &br);//ֵ��
	static SET fldR(const Binary_relationship &br);//����
	bool Reflexive(const SET &S);//s1�Է�
	bool Anti_reflexive(const SET &S);//���Է�

	~Binary_relationship();

	friend ostream &operator<<(ostream &os, Binary_relationship &BR);

private:
	SET Date;
};

Binary_relationship::Binary_relationship()
{
}

inline Binary_relationship::Binary_relationship(SET &S)
{
	Date = S * S;
}

inline Binary_relationship Binary_relationship::E(SET &S)
{
	Binary_relationship Temp;
	Temp.Date = S * S;
	return Temp;
}

inline Binary_relationship Binary_relationship::I(const SET& S)
{
	Binary_relationship temp;
	for (int i : S.IS)
		temp.Date.push(ordinal_pair(i, i));
	for (char ch : S.CHS)
		temp.Date.push(ordinal_pair(ch, ch));
	for (string s : S.STRS)
		temp.Date.push(ordinal_pair(s, s));
	for (SET T : S.SETS)
		temp.Date.push(ordinal_pair(T, T));
	for (ordinal_pair op : S.OPS)
		temp.Date.push(ordinal_pair(op, op));
	return temp;

}

inline Binary_relationship Binary_relationship::L(const SET & S)
{
	Binary_relationship temp;
	if(S.CHS.size()>0||S.STRS.size()>0||S.SETS.size()>0||S.OPS.size()>0||S.IS.size()==0)
		return Binary_relationship();

	for (int i1 : S.IS)
		for (int i2 : S.IS)
			if (i1 <= i2)
				temp.Date.push(ordinal_pair(i1, i2));
	return temp;
}

inline Binary_relationship Binary_relationship::D(const SET & S)
{
	Binary_relationship temp;
	if (S.CHS.size() > 0 || S.STRS.size() > 0 || S.SETS.size() > 0 || S.OPS.size() > 0 || S.IS.size() == 0)
		return Binary_relationship();
	for (int i1 : S.IS)
		for (int i2 : S.IS)
			if (i2%i1 == 0)
				temp.Date.push(ordinal_pair(i1, i2));
	return temp;
	
}

inline Binary_relationship Binary_relationship::R(const SET & S)
{
	Binary_relationship temp;
	if (S.CHS.size() > 0 || S.STRS.size() > 0 || S.OPS.size() > 0 || S.IS.size() > 0 || S.SETS.size() == 0)
		return Binary_relationship();
	for (SET T1 : S.SETS)
	{
		for (SET T2 : S.SETS)
		{
			SET::iterator it3 = T2.begin();
			for (; it3 != T2.end(); ++it3)
			{
				if (!T1.find(*it3))
					break;
			}
			if (it3 == T2.end())
				temp.Date.push(ordinal_pair(T1, T2));
		}
	}
	return temp;
		
}

inline Binary_relationship::Binary_relationship(SET &S1, SET &S2)
{
	Date = S1 * S2;
}

inline SET Binary_relationship::domR(const Binary_relationship &br)
{
	SET temp;
	for(ordinal_pair T:br.Date.OPS)
		switch (T.type1)
		{
		case Int:
			temp.push(*T.I[0]);
			break;
		case Char:
			temp.push(*T.CH[0]);
			break;
		case Str:
			temp.push(*T.STR[0]);
			break;
		case Set:
			temp.push(*T.SETT[0]);
			break;
		case Ordinal_pair:
			temp.push(*T.OP[0]);
			break;
		default:
			break;
		}
	return temp;
}


inline SET Binary_relationship::ranR(const Binary_relationship & br)
{
	SET temp;
	for (ordinal_pair T : br.Date.OPS)
		switch (T.type2)
		{
		case Int:
			temp.push(*T.I[1]);
			break;
		case Char:
			temp.push(*T.CH[1]);
			break;
		case Str:
			temp.push(*T.STR[1]);
			break;
		case Set:
			temp.push(*T.SETT[1]);
			break;
		case Ordinal_pair:
			temp.push(*T.OP[1]);
			break;
		default:
			break;
		}
	return temp;
}

inline SET Binary_relationship::fldR(const Binary_relationship & br)
{
	SET temp = domR(br) + ranR(br);
	return temp;
}

inline bool Binary_relationship::Reflexive(const SET & S)
{
	for (int i : S.IS)
		if (!Date.find(SET({ ordinal_pair(i,i) })))
			return false;
	for (char i : S.CHS)
		if (!Date.find(SET({ ordinal_pair(i,i) })))
			return false;
	for (string i : S.STRS)
		if (!Date.find(SET({ ordinal_pair(i,i) })))
			return false;
	for (SET i : S.SETS)
		if (!Date.find(SET({ ordinal_pair(i,i) })))
			return false;
	for (ordinal_pair i : S.OPS)
		if (!Date.find(SET({ ordinal_pair(i,i) })))
			return false;

	return true;
}

inline bool Binary_relationship::Anti_reflexive(const SET & S)
{
	for (int i : S.IS)
		if (Date.find(SET({ ordinal_pair(i,i) })))
			return false;
	for (char i : S.CHS)
		if (Date.find(SET({ ordinal_pair(i,i) })))
			return false;
	for (string i : S.STRS)
		if (Date.find(SET({ ordinal_pair(i,i) })))
			return false;
	for (SET i : S.SETS)
		if (Date.find(SET({ ordinal_pair(i,i) })))
			return false;
	for (ordinal_pair i : S.OPS)
		if (Date.find(SET({ ordinal_pair(i,i) })))
			return false;

	return true;
}

inline Binary_relationship::~Binary_relationship()
{
}

ostream & operator<<(ostream & os, Binary_relationship & BR)
{
	os << BR.Date;
	// TODO: �ڴ˴����� return ���
	return os;
}