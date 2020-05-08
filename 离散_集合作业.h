#pragma once
#include<set>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class SET;//SET������
class ordinal_pair;//��ż������
ostream & operator<<(ostream & os, SET & S);//SET������<<����
ostream & operator<<(ostream & os, ordinal_pair & op);//��ż������<<����
enum types//ö�����Ͷ�������
{
	Int, Char, Str, Set, Ordinal_pair, null
};


/************��ż��������**************/
class ordinal_pair
{
public:
	/*************���캯����5*5+2���أ�****************/
	ordinal_pair();
	ordinal_pair(const ordinal_pair& op);
	ordinal_pair(int t1, int t2);
	ordinal_pair(int t1, char t2);
	ordinal_pair(int t1, string t2);
	ordinal_pair(int t1, SET t2);
	ordinal_pair(int t1, ordinal_pair t2);
	ordinal_pair(char t1, int t2);
	ordinal_pair(char t1, char t2);
	ordinal_pair(char t1, string t2);
	ordinal_pair(char t1, SET t2);
	ordinal_pair(char t1, ordinal_pair t2);
	ordinal_pair(string t1, int t2);
	ordinal_pair(string t1, char t2);
	ordinal_pair(string t1, string t2);
	ordinal_pair(string t1, SET t2);
	ordinal_pair(string t1, ordinal_pair t2);
	ordinal_pair(SET t1, int t2);
	ordinal_pair(SET t1, char t2);
	ordinal_pair(SET t1, string t2);
	ordinal_pair(SET t1, SET t2);
	ordinal_pair(SET t1, ordinal_pair t2);
	ordinal_pair(ordinal_pair t1, int t2);
	ordinal_pair(ordinal_pair t1, char t2);
	ordinal_pair(ordinal_pair t1, string t2);
	ordinal_pair(ordinal_pair t1, SET t2);
	ordinal_pair(ordinal_pair t1, ordinal_pair t2);

	void operator=(const ordinal_pair& op);//���ظ�ֵ����
	~ordinal_pair();//��������
	bool operator==(const ordinal_pair & O);//���ط���==
	bool operator<(const ordinal_pair & op) const { return (OPHash() < op.OPHash()); };//���ط���<
	friend ostream& operator<<(ostream &os, ordinal_pair & op);//�������ط���<<(��Ԫ)

	/**********��һ���ڶ��������ú�����5*2���أ�************/
	void component1(int t);
	void component1(char t);
	void component1(string t);
	void component1(SET t);
	void component1(ordinal_pair t);
	void component2(int t);
	void component2(char t);
	void component2(string t);
	void component2(SET t);
	void component2(ordinal_pair t);

	size_t OPHash() const;//��ż�����������������ڲ�ͬ��ż�����ıȽ�

private:
	enum types type1,type2;//��һ���ڶ���������

	/********����������ݣ�����int,char,string,SET����ż������Ϊ����*******/
	int I[2];
	char CH[2];
	string STR[2];
	SET * SETT[2];
	ordinal_pair * OP[2];

};




/**************SET��������****************/
class SET
{
public:
	/******************���캯����7���أ�*******************/
	SET() { Empty = true; };
	SET(const SET &S);
	SET(initializer_list<int> I) { IS.insert(I); };
	SET(initializer_list<char> ch) { CHS.insert(ch); };
	SET(initializer_list<string> str) { STRS.insert(str); };
	SET(initializer_list<ordinal_pair> op) { OPS.insert(op); };
	SET(initializer_list<SET> Set) { SETS.insert(Set); };

	~SET() {};//��������

	bool operator==(const SET & S);//����==
	void operator=(const SET&S);//���ظ�ֵ����
	inline bool operator<(const SET &S) const { return SETHash() < S.SETHash(); };//����<
	SET operator+(const SET & S);//����+��������
	SET operator&&(const SET & S);//����&��������
	SET operator-(const SET & S);//����-�����
	SET operator*(const SET & S);//����*���ѿ�������
	SET power();//�ݼ�
	void power(int i,SET T,SET* Res);//�ݼ�ִ�к���
	friend SET Symmetrical_difference(const SET & S1, const SET & S2);//�ԳƲ��Ԫ��
	friend ostream& operator<<(ostream &os, SET & S);//�������ط���<<(��Ԫ)
	size_t size() const;//����Ԫ�ظ���
	size_t SETHash() const;//SET�����������������ڲ�ͬ��ż�����ıȽ�
	
	/*****************���Ԫ�غ�����5���أ�*******************/
	inline void push(int I) { IS.insert(I); Empty = false; };
	inline void push(char ch) { CHS.insert(ch); Empty = false; };
	inline void push(string str) { STRS.insert(str); Empty = false; };
	inline void push(SET Set) { SETS.insert(Set); Empty = false; };
	inline void push(ordinal_pair op) { OPS.insert(op); Empty = false; };
	inline void push(initializer_list<int> I) { IS.insert(I); Empty = false; };
	inline void push(initializer_list<char> ch) { CHS.insert(ch); Empty = false; };
	inline void push(initializer_list<string> str) { STRS.insert(str); Empty = false; };
	inline void push(initializer_list<SET> Set) { SETS.insert(Set); Empty = false; };
	inline void push(initializer_list<ordinal_pair> op) { OPS.insert(op); Empty = false; };

private:
	bool Empty;//�Ƿ�����ռ�

	/*����Ԫ�����ݣ�����int,char,string,SET����ż������ΪԪ��*/
	set<int>IS;
	set<char>CHS;
	set<string>STRS;
	set<SET>SETS;
	set<ordinal_pair>OPS;

};



/************************��ż��������****************************/

void ordinal_pair::operator=(const ordinal_pair & op)
{
	type1 = op.type1;
	type2 = op.type2;
	switch (type1)
	{
	case Int:
		I[0] = op.I[0];
		break;
	case Char:
		CH[0] = op.CH[0];
		break;
	case Str:
		STR[0] = op.STR[0];
		break;
	case Set:
		delete SETT[0];
		SETT[0] = new SET;
		*SETT[0] = *op.SETT[0];
		break;
	case Ordinal_pair:
		delete OP[0];
		OP[0] = new ordinal_pair;
		*OP[0] = *op.OP[0];
		break;
	case null:
		break;
	default:
		break;
	}
	switch (type2)
	{
	case Int:
		I[1] = op.I[1];
		break;
	case Char:
		CH[1] = op.CH[1];
		break;
	case Str:
		STR[1] = op.STR[1];
		break;
	case Set:
		delete SETT[1];
		SETT[1] = new SET;
		*SETT[1] = *op.SETT[1];
		break;
	case Ordinal_pair:
		delete OP[1];
		OP[1] = new ordinal_pair;
		*OP[1] = *op.OP[1];
		break;
	case null:
		break;
	default:
		break;
	}

}

ordinal_pair::ordinal_pair()
{
	type1 = null;
	type2 = null;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
}

inline ordinal_pair::~ordinal_pair()
{
	if (SETT[0] != NULL)
		delete SETT[0]; SETT[0] = NULL;
	if (SETT[1] != NULL)
		delete SETT[1]; SETT[1] = NULL;
	if (OP[0] != NULL)
		delete OP[0]; OP[0] = NULL;
	if (OP[1] != NULL)
		delete OP[1]; OP[1] = NULL;
}

ordinal_pair::ordinal_pair(const ordinal_pair & op)
{
	type1 = op.type1;
	type2 = op.type2;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	switch (type1)
	{
	case Int:
		I[0] = op.I[0];
		break;
	case Char:
		CH[0] = op.CH[0];
		break;
	case Str:
		STR[0] = op.STR[0];
		break;
	case Set:
		SETT[0] = new SET;
		*SETT[0] = *op.SETT[0];
		break;
	case Ordinal_pair:
		OP[0] = new ordinal_pair;
		*OP[0] = *op.OP[0];
		break;
	case null:
		break;
	default:
		break;
	}
	switch (type2)
	{
	case Int:
		I[1] = op.I[1];
		break;
	case Char:
		CH[1] = op.CH[1];
		break;
	case Str:
		STR[1] = op.STR[1];
		break;
	case Set:
		SETT[1] = new SET;
		*SETT[1] = *op.SETT[1];
		break;
	case Ordinal_pair:
		OP[1] = new ordinal_pair;
		*OP[1] = *op.OP[1];
		break;
	case null:
		break;
	default:
		break;
	}
}

inline ordinal_pair::ordinal_pair(int t1, int t2)
{
	type1 = Int;
	type2 = Int;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	I[0] = t1;
	I[1] = t2;
}
inline ordinal_pair::ordinal_pair(int t1, char t2)
{
	type1 = Int;
	type2 = Char;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	I[0] = t1;
	CH[1] = t2;
}
inline ordinal_pair::ordinal_pair(int t1, string t2)
{
	type1 = Int;
	type2 = Str;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	I[0] = t1;
	STR[1] = t2;
}
inline ordinal_pair::ordinal_pair(int t1, SET t2)
{
	type1 = Int;
	type2 = Set;
	SETT[0] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	I[0] = t1;
	SETT[1] = new SET;
	*SETT[1] = t2;
}
inline ordinal_pair::ordinal_pair(int t1, ordinal_pair t2)
{
	type1 = Int;
	type2 = Ordinal_pair;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	I[0] = t1;
	OP[1] = new ordinal_pair;
	*OP[1] = t2;
}
inline ordinal_pair::ordinal_pair(char t1, int t2)
{
	type1 = Char;
	type2 = Int;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	CH[0] = t1;
	I[1] = t2;
}
inline ordinal_pair::ordinal_pair(char t1, char t2)
{
	type1 = Char;
	type2 = Char;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	CH[0] = t1;
	CH[1] = t2;
}
inline ordinal_pair::ordinal_pair(char t1, string t2)
{
	type1 = Char;
	type2 = Str;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	CH[0] = t1;
	STR[1] = t2;
}
inline ordinal_pair::ordinal_pair(char t1, SET t2)
{
	type1 = Char;
	type2 = Set;
	SETT[0] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	CH[0] = t1;
	SETT[1] = new SET;
	*SETT[1] = t2;
}
inline ordinal_pair::ordinal_pair(char t1, ordinal_pair t2)
{
	type1 = Char;
	type2 = Ordinal_pair;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	CH[0] = t1;
	OP[1] = new ordinal_pair;
	*OP[1] = t2;
}
inline ordinal_pair::ordinal_pair(string t1, int t2)
{
	type1 = Str;
	type2 = Int;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	STR[0] = t1;
	I[1] = t2;
}
inline ordinal_pair::ordinal_pair(string t1, char t2)
{
	type1 = Str;
	type2 = Char;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	STR[0] = t1;
	CH[1] = t2;
}
inline ordinal_pair::ordinal_pair(string t1, string t2)
{
	type1 = Str;
	type2 = Str;
	STR[0] = t1;
	STR[1] = t2;
}
inline ordinal_pair::ordinal_pair(string t1, SET t2)
{
	type1 = Str;
	type2 = Set;
	SETT[0] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	STR[0] = t1;
	SETT[1] = new SET;
	*SETT[1] = t2;
}
inline ordinal_pair::ordinal_pair(string t1, ordinal_pair t2)
{
	type1 = Str;
	type2 = Ordinal_pair;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = NULL;
	STR[0] = t1;
	OP[1] = new ordinal_pair;
	*OP[1] = t2;
}
inline ordinal_pair::ordinal_pair(SET t1, int t2)
{
	type1 = Set;
	type2 = Int;;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	SETT[0] = new SET;
	*SETT[0] = t1;
	I[1] = t2;
}
inline ordinal_pair::ordinal_pair(SET t1, char t2)
{
	type1 = Set;
	type2 = Char;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	SETT[0] = new SET;
	*SETT[0] = t1;
	CH[1] = t2;
}
inline ordinal_pair::ordinal_pair(SET t1, string t2)
{
	type1 = Set;
	type2 = Str;
	SETT[1] = NULL;
	OP[0] = NULL;
	OP[1] = NULL;
	SETT[0] = new SET;
	*SETT[0] = t1;
	STR[1] = t2;
}
inline ordinal_pair::ordinal_pair(SET t1, SET t2)
{
	type1 = Set;
	type2 = Set;
	OP[0] = NULL;
	OP[1] = NULL;
	SETT[0] = new SET;
	*SETT[0] = t1;
	SETT[1] = new SET;
	*SETT[1] = t2;
}
inline ordinal_pair::ordinal_pair(SET t1, ordinal_pair t2)
{
	type1 = Set;
	type2 = Ordinal_pair;
	SETT[1] = NULL;
	OP[0] = NULL;
	SETT[0] = new SET;
	*SETT[0] = t1;
	OP[1] = new ordinal_pair;
	*OP[1] = t2;
}
inline ordinal_pair::ordinal_pair(ordinal_pair t1, int t2)
{
	type1 = Ordinal_pair;
	type2 = Int;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[1] = NULL;
	OP[0] = new ordinal_pair;
	*OP[0] = t1;
	I[1] = t2;
}
inline ordinal_pair::ordinal_pair(ordinal_pair t1, char t2)
{
	type1 = Ordinal_pair;
	type2 = Char;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[1] = NULL;
	OP[0] = new ordinal_pair;
	*OP[0] = t1;
	CH[1] = t2;
}
inline ordinal_pair::ordinal_pair(ordinal_pair t1, string t2)
{
	type1 = Ordinal_pair;
	type2 = Str;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[1] = NULL;
	OP[0] = new ordinal_pair;
	*OP[0] = t1;
	STR[1] = t2;
}
inline ordinal_pair::ordinal_pair(ordinal_pair t1, SET t2)
{
	type1 = Ordinal_pair;
	type2 = Set;
	SETT[0] = NULL;
	OP[1] = NULL;
	OP[0] = new ordinal_pair;
	*OP[0] = t1;
	SETT[1] = new SET;
	*SETT[1] = t2;
}
inline ordinal_pair::ordinal_pair(ordinal_pair t1, ordinal_pair t2)
{
	type1 = Ordinal_pair;
	type2 = Ordinal_pair;
	SETT[0] = NULL;
	SETT[1] = NULL;
	OP[0] = new ordinal_pair;
	*OP[0] = t1;
	OP[1] = new ordinal_pair;
	*OP[1] = t2;
}
inline void ordinal_pair::component1(int t)
{
	type1 = Int;
	I[0] = t;
}
inline void ordinal_pair::component1(char t)
{
	type1 = Char;
	CH[0] = t;
}
inline void ordinal_pair::component1(string t)
{
	type1 = Str;
	STR[0] = t;
}
inline void ordinal_pair::component1(SET t)
{
	type1 = Set;
	delete SETT[0];
	SETT[0] = new SET;
	*SETT[0] = t;
}
inline void ordinal_pair::component1(ordinal_pair t)
{
	type1 = Ordinal_pair;
	delete OP[0];
	OP[0] = new ordinal_pair;
	*OP[0] = t;
}
inline void ordinal_pair::component2(int t)
{
	type1 = Int;
	I[1] = t;
}
inline void ordinal_pair::component2(char t)
{
	type1 = Char;
	CH[1] = t;
}
inline void ordinal_pair::component2(string t)
{
	type1 = Str;
	STR[1] = t;
}
inline void ordinal_pair::component2(SET t)
{
	type1 = Set;
	delete SETT[1];
	SETT[1] = new SET;
	*SETT[1] = t;
}
inline void ordinal_pair::component2(ordinal_pair t)
{
	type1 = Ordinal_pair;
	delete OP[1];
	OP[1] = new ordinal_pair;
	*OP[1] = t;
}

inline size_t ordinal_pair::OPHash() const
{
	size_t s = type1 * 10000 + type2 * 100000;
	switch (type1)
	{
	case Int:
		s += I[0]*200;
		break;
	case Char:
		s += CH[0]*400;
		break;
	case Str:
		s = (s + STR[0].length() + STR[0].at(0))*1000;
		break;
	case Set:
		s += SETT[0]->SETHash()/1000;
		break;
	case Ordinal_pair:
		s += OP[0]->OPHash()/200;
		break;
	case null:
		break;
	default:
		break;
	}
	switch (type2)
	{
	case Int:
		s += I[1]*100;
		break;
	case Char:
		s += CH[1]*300;
		break;
	case Str:
		s = (s + STR[1].length() + STR[1].at(0))*900;
		break;
	case Set:
		s += SETT[1]->SETHash() / 900;
		break;
	case Ordinal_pair:
		s += OP[1]->OPHash() / 100;
		break;
	case null:
		break;
	default:
		break;
	}
	return s;
}

bool ordinal_pair::operator==(const ordinal_pair & op)
{
	if (type1 == op.type1&&type2 == op.type2)
	{
		switch (type1)
		{
		case Int:
			if (I[0] != op.I[0])
				return false;
			break;
		case Char:
			if (CH[0] != op.CH[0])
				return false;
			break;
		case Str:
			if (STR[0] != op.STR[0])
				return false;
			break;
		case Set:
			if (!(*SETT[0] == *op.SETT[0]))
				return false;
			break;
		case Ordinal_pair:
			if (!(*OP[0] == *op.OP[0]))
				return false;
			break;
		case null:
			break;
		default:
			break;
		}
		switch (type2)
		{
		case Int:
			if (I[1] != op.I[1])
				return false;
			break;
		case Char:
			if (CH[1] != op.CH[1])
				return false;
			break;
		case Str:
			if (STR[1] != op.STR[1])
				return false;
			break;
		case Set:
			if (!(*SETT[1] == *op.SETT[1]))
				return false;
			break;
		case Ordinal_pair:
			if (!(*OP[1] == *op.OP[1]))
				return false;
			break;
		case null:
			break;
		default:
			break;
		}
		return true;
	}
	else
		return false;

}

ostream & operator<<(ostream & os, ordinal_pair & op)
{
	os << '<';
	switch (op.type1)
	{
	case Int:
		os << op.I[0];
		break;
	case Char:
		os << '\'' << op.CH[0] << '\'';
		break;
	case Str:
		os << '"' << op.STR[0] << '"';
		break;
	case Set:
		os << *op.SETT[0];
		break;
	case Ordinal_pair:
		os << *op.OP[0];
		break;
	case null:
		os << "NULL";
		break;
	default:
		break;
	}
	os << ",";
	switch (op.type2)
	{
	case Int:
		os << op.I[1];
		break;
	case Char:
		os << '\'' << op.CH[1] << '\'';
		break;
	case Str:
		os << '"' << op.STR[1] << '"';
		break;
	case Set:
		os << *op.SETT[1];
		break;
	case Ordinal_pair:
		os << *op.OP[1];
		break;
	case null:
		os << "NULL";
		break;
	default:
		break;
	}
	os << '>';
	return os;
	// TODO: �ڴ˴����� return ���
}




/********************SET��������***********************/
SET::SET(const SET & S)
{
	Empty = S.Empty;
	IS = S.IS;
	CHS = S.CHS;
	STRS = S.STRS;
	SETS = S.SETS;
	OPS = S.OPS;
}

inline void SET::operator=(const SET & S)
{
	Empty = S.Empty;
	IS = S.IS;
	CHS = S.CHS;
	STRS = S.STRS;
	SETS = S.SETS;
	OPS = S.OPS;
}


bool SET::operator==(const SET & S)
{
	if(Empty == S.Empty&&IS == S.IS && CHS == S.CHS && STRS == S.STRS);
	{
		for (SET TSET : SETS)
			if (S.SETS.find(TSET) == S.SETS.end())
				return false;
		for (SET TSET : S.SETS)
			if (SETS.find(TSET) == SETS.end())
				return false;
		return true;
	}
	
}

SET SET::operator+(const SET & S)
{
	SET Temp = S;
	Temp.IS.insert(IS.begin(), IS.end());
	Temp.CHS.insert(CHS.begin(), CHS.end());
	Temp.STRS.insert(STRS.begin(), STRS.end());
	Temp.SETS.insert(SETS.begin(), SETS.end());
	Temp.OPS.insert(OPS.begin(), OPS.end());
	return Temp;
	// TODO: �ڴ˴����� return ���
}

SET SET::operator&&(const SET & S)
{
	SET Temp;
	for (int i : IS)
		if (S.IS.find(i) != S.IS.end())
			Temp.push(i);

	for (char ch : CHS)
		if (S.CHS.find(ch) != S.CHS.end())
			Temp.push(ch);

	for (string str : STRS)
		if (S.STRS.find(str) != S.STRS.end())
			Temp.push(str);

	for (SET Set : SETS)
		if (S.SETS.find(Set) != S.SETS.end())
			Temp.push(Set);
	for (ordinal_pair op : OPS)
		if (S.OPS.find(op) != S.OPS.end())
			Temp.push(op);
	return Temp;
	// TODO: �ڴ˴����� return ���
}

SET SET::operator-(const SET & S)
{
	SET Temp;
	for (int i : IS)
		if (S.IS.find(i) == S.IS.end())
			Temp.push(i);

	for (char ch : CHS)
		if (S.CHS.find(ch) == S.CHS.end())
			Temp.push(ch);

	for (string str : STRS)
		if (S.STRS.find(str) == S.STRS.end())
			Temp.push(str);

	for (SET Set : SETS)
		if (S.SETS.find(Set) == S.SETS.end())
			Temp.push(Set);
	for (ordinal_pair op : OPS)
		if (S.OPS.find(op) == S.OPS.end())
			Temp.push(op);
	return Temp;

	// TODO: �ڴ˴����� return ���
}

SET Symmetrical_difference(const SET & S1, const SET & S2)
{
	SET Temp;
	for (int i : S1.IS)
		if (S2.IS.find(i) == S2.IS.end())
			Temp.push(i);

	for (char ch : S1.CHS)
		if (S2.CHS.find(ch) == S2.CHS.end())
			Temp.push(ch);

	for (string str : S1.STRS)
		if (S2.STRS.find(str) == S2.STRS.end())
			Temp.push(str);

	for (SET Set : S1.SETS)
		if (S2.SETS.find(Set) == S2.SETS.end())
			Temp.push(Set);
	for (ordinal_pair op : S1.OPS)
		if (S2.OPS.find(op) == S2.OPS.end())
			Temp.push(op);

	for (int i : S2.IS)
		if (S1.IS.find(i) == S1.IS.end())
			Temp.push(i);

	for (char ch : S2.CHS)
		if (S1.CHS.find(ch) == S1.CHS.end())
			Temp.push(ch);

	for (string str : S2.STRS)
		if (S1.STRS.find(str) == S1.STRS.end())
			Temp.push(str);

	for (SET Set : S2.SETS)
		if (S1.SETS.find(Set) == S1.SETS.end())
			Temp.push(Set);
	for (ordinal_pair op : S2.OPS)
		if (S1.OPS.find(op) == S1.OPS.end())
			Temp.push(op);
	return Temp;
	// TODO: �ڴ˴����� return ���
}

SET SET::operator*(const SET & S)
{
	SET Stemp;
	for (int i1 : IS)
	{
		for (int i2 : S.IS)
		{
			ordinal_pair OPTemp(i1, i2);
			Stemp.push(OPTemp);
		}
		for (char ch2 : S.CHS)
		{
			ordinal_pair OPTemp(i1, ch2);;
			Stemp.push(OPTemp);
		}
		for (string str2 : S.STRS)
		{
			ordinal_pair OPTemp(i1, str2);
			Stemp.push(OPTemp);
		}
		for (SET SET2 : S.SETS)
		{
			ordinal_pair OPTemp(i1, SET2);
			Stemp.push(OPTemp);
		}
		for (ordinal_pair OP2 : S.OPS)
		{
			ordinal_pair OPTemp(i1, OP2);
			Stemp.push(OPTemp);
		}
	}
	for (char ch1 : CHS)
	{
		for (int i2 : S.IS)
		{
			ordinal_pair OPTemp( ch1, i2);
			Stemp.push(OPTemp);
		}
		for (char ch2 : S.CHS)
		{
			ordinal_pair OPTemp(ch1, ch2);
			Stemp.push(OPTemp);
		}
		for (string str2 : S.STRS)
		{
			ordinal_pair OPTemp(ch1, str2);
			Stemp.push(OPTemp);
		}
		for (SET SET2 : S.SETS)
		{
			ordinal_pair OPTemp(ch1, SET2);
			Stemp.push(OPTemp);
		}
		for (ordinal_pair OP2 : S.OPS)
		{
			ordinal_pair OPTemp(ch1, OP2);
			Stemp.push(OPTemp);
		}
	}
	for (string str1 : STRS)
	{
		for (int i2 : S.IS)
		{
			ordinal_pair OPTemp(str1, i2);
			Stemp.push(OPTemp);
		}
		for (char ch2 : S.CHS)
		{
			ordinal_pair OPTemp(str1, ch2);
			Stemp.push(OPTemp);
		}
		for (string str2 : S.STRS)
		{
			ordinal_pair OPTemp(str1, str2);
			Stemp.push(OPTemp);
		}
		for (SET SET2 : S.SETS)
		{
			ordinal_pair OPTemp(str1, SET2);
			Stemp.push(OPTemp);
		}
		for (ordinal_pair OP2 : S.OPS)
		{
			ordinal_pair OPTemp(str1, OP2);
			Stemp.push(OPTemp);
		}
	}
	for (SET SET1 : SETS)
	{
		for (int i2 : S.IS)
		{
			ordinal_pair OPTemp(SET1, i2);
			Stemp.push(OPTemp);
		}
		for (char ch2 : S.CHS)
		{
			ordinal_pair OPTemp(SET1, ch2);
			Stemp.push(OPTemp);
		}
		for (string str2 : S.STRS)
		{
			ordinal_pair OPTemp(SET1, str2);
			Stemp.push(OPTemp);
		}
		for (SET SET2 : S.SETS)
		{
			ordinal_pair OPTemp(SET1, SET2);
			Stemp.push(OPTemp);
		}
		for (ordinal_pair OP2 : S.OPS)
		{
			ordinal_pair OPTemp(SET1, OP2);
			Stemp.push(OPTemp);
		}
	}
	for (ordinal_pair op1 : OPS)
	{
		for (int i2 : S.IS)
		{
			ordinal_pair OPTemp(op1, i2);
			Stemp.push(OPTemp);
		}
		for (char ch2 : S.CHS)
		{
			ordinal_pair OPTemp(op1, ch2);
			Stemp.push(OPTemp);
		}
		for (string str2 : S.STRS)
		{
			ordinal_pair OPTemp(op1, str2);
			Stemp.push(OPTemp);
		}
		for (SET SET2 : S.SETS)
		{
			ordinal_pair OPTemp(op1, SET2);
			Stemp.push(OPTemp);
		}
		for (ordinal_pair OP2 : S.OPS)
		{
			ordinal_pair OPTemp(op1, OP2);
			Stemp.push(OPTemp);
		}
	}
		
	return Stemp;
	// TODO: �ڴ˴����� return ���
}

void SET::power(int i, SET T, SET* Res)
{
	if (i == size())
	{
		Res->push(T);
		return;
	}
	else
	{
		power(i + 1, T, Res);
		int ii = i;
		if (ii < IS.size())
		{
			set<int>::iterator isi = IS.begin();
			for (int I = 0; I < ii; I++)
				isi++;
			T.push(*isi);
		}
		else
		{
			ii -= IS.size();
			if (ii < CHS.size())
			{
				set<char>::iterator chsi = CHS.begin();
				for(int I = 0; I < ii; I++)
					chsi++;
				T.push(*chsi);
			}
			else
			{
				ii -= CHS.size();
				if (ii < STRS.size())
				{
					set<string>::iterator strsi = STRS.begin();
					for(int I = 0; I < ii; I++)
						strsi++;
					T.push(*strsi);
				}
				else
				{
					i -= STRS.size();
					if (ii < SETS.size())
					{
						set<SET>::iterator setsi = SETS.begin();
						for(int I = 0; I < ii; I++)
							setsi++;
						T.push(*setsi);
					}
					else
					{
						ii -= SETS.size();
						if (ii < OPS.size())
						{
							set<ordinal_pair>::iterator opsi = OPS.begin();
							for(int I = 0; I < ii; I++)
								opsi++;
							T.push(*opsi);
						}
					}
				}
			}
		}
		power(i + 1, T, Res);
	}
}

inline SET SET::power()
{
	SET RES;
	power(0, SET(), &RES);
	return RES;
}


ostream & operator<<(ostream & os, SET & S)
{
	os << '{';
	for (int i : S.IS)
		os << i << ',';

	for (char ch : S.CHS)
		os <<'\''<< ch <<'\''<< ',';

	for (string str : S.STRS)
		os << '"' << str << '"' << ',';

	for (SET SET1 : S.SETS)
		os << SET1 << ',';

	for (ordinal_pair op : S.OPS)
		os << op << ',';

	if (S.Empty)
		cout << "Empty_set";
	else
		cout << "\b";
	cout << '}';

	return os;

	// TODO: �ڴ˴����� return ���
}

inline size_t SET::size() const
{
	return IS.size()+CHS.size()+STRS.size()+SETS.size()+OPS.size();
}

size_t SET::SETHash() const
{
	size_t s = size()*100000;
	set<int>::iterator isi = IS.begin();
	set<char>::iterator chsi = CHS.begin();
	set<string>::iterator strsi = STRS.begin();
	set<SET>::iterator setsi = SETS.begin();
	set<ordinal_pair>::iterator opsi = OPS.begin();
	for (int i = 1; i <= IS.size(); i++)
	{
		s += *isi * i * 100;
		isi++;
	}
	for (int i = 1; i <= CHS.size(); i++)
	{
		s += *chsi * i * 1000;
		chsi++;
	}
	for (int i = 1; i <= STRS.size(); i++)
	{
		s += (strsi->length() + strsi->at(0)) * i * 10000;
		isi++;
	}
	for (int i = 1; i <= SETS.size(); i++)
	{
		s += setsi->SETHash()/5000 * i;
		setsi++;
	}
	for (int i = 1; i <= OPS.size(); i++)
	{
		s += opsi->OPHash() / 10000 * i;
		opsi++;
	}
	return s;
}