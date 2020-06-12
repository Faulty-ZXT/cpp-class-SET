#pragma once
#include <set>
#include "discrete_SET.h"
#include "myGraph.h"

class Graphs
{
public:
	Graphs();								  					//����
	Graphs(size_t v, MSET &S2);				  					//�вι��죺v:������Ŀ S2:��
	static bool Is_Graphs(size_t v, MSET S2); 					//�жϱ��붥���Ƿ�ƥ��
	~Graphs();								 					 //����

	static Graphs G(size_t v, MSET S2);							//��������������ͼ
	static Graphs E(size_t v, MSET S2);							//��������������ͼ
	size_t V_size() { return V_num; };							//��������(n��ͼ)
	size_t E_size();											//������
	bool EG_empty();											//�ж���ͼ
	bool Figure_empty() { return V_num == 0; };					//�жϿ�ͼ
	static unsigned int Associations(Date d, MSET S);			//��������
	bool V_Adjacent(size_t d1, size_t d2);						//�ж϶����Ƿ�����
	static bool E_Adjacent(MSET S1, MSET S2);					//�ж�������Ƿ�����
	static bool E_Adjacent(ordinal_pair op1, ordinal_pair op2); //�ж�����ͼ�Ƿ�����
	unsigned int link_branch();									//��ͨ����
	void print();												//��ӡ�ڽӾ���

private:
	size_t V_num;													   //��������
	Matrix *arrey;													   //�ڽӾ���
	bool Is_Direct;													   //�Ƿ�����
	void link_branch(int d, set<int> &traversaled, unsigned int &sum); //��ͨ��������ִ�к���
};

Graphs::Graphs()
{
	V_num = 0;
	arrey = NULL;
}

inline bool Graphs::Is_Graphs(size_t v, MSET S2)
{
	types T = (*S2.begin()).ty();
	if (T != Ordinal_pair && T != MSet)
		return false;

	for (Date d : S2)
	{
		if (d.ty() != T)
			return false;
	}
	for (Date d : S2)
	{
		switch (d.ty())
		{
		case Ordinal_pair:
			if ((d.OP().date1().I() > v) && (d.OP().date2().I() > v))
				return false;
			break;
		case MSet:
		{
			for (Date d2 : d.MSETT())
				if (d2.I() > v)
					return false;
			break;
		}
		default:
			break;
		}
	}
	return true;
}

inline Graphs::Graphs(size_t v, MSET &S2)
{
	if (!Is_Graphs(v, S2))
	{
		std::cout << "it is not a Graphs!" << endl;
		return;
	}
	V_num = v;
	arrey = new Matrix(v, v);
	if ((*S2.begin()).ty() == Ordinal_pair)
	{
		Is_Direct = true;
		for (Date d : S2)
			arrey->array[(d.OP().date1().I()) - 1][(d.OP().date2().I()) - 1]++;
	}
	else
	{
		Is_Direct = false;
		for (Date d : S2)
		{
			size_t x1 = (*d.MSETT().begin()).I();
			size_t x2 = (*(++d.MSETT().begin())).I();
			x1 > x2 ? arrey->array[--x1][--x2]++ : arrey->array[--x2][--x1]++;
		}
	}
}

inline size_t Graphs::E_size()
{
	size_t sum = 0;
	if (Is_Direct)
	{
		for (size_t x = 0; x < V_num; x++)
			for (size_t y = 0; y < V_num; y++)
				sum += arrey->array[x][y];
	}
	else
	{
		for (size_t x = 0; x < V_num; x++)
			for (size_t y = 0; y <= x; y++)
				sum += arrey->array[x][y];
	}
	return 0;
}

inline bool Graphs::EG_empty()
{
	if (arrey == NULL || V_num == 0)
		return true;
	if (Is_Direct)
	{
		for (size_t x = 0; x < V_num; x++)
			for (size_t y = 0; y < V_num; y++)
				if (!arrey->array[x][y])
					return false;
	}
	else
	{
		for (size_t x = 0; x < V_num; x++)
			for (size_t y = 0; y <= x; y++)
				if (arrey->array[x][y])
					return false;
	}
}

Graphs::~Graphs()
{
	if (arrey != NULL)
		delete arrey;
	arrey = NULL;
}

inline Graphs Graphs::G(size_t v, MSET S2)
{
	if ((*S2.begin()).ty() != MSet)
	{
		std::cout << "this is not a Undirected graph!" << std::endl;
		return Graphs();
	}
	return Graphs(v, S2);
}

inline Graphs Graphs::E(size_t v, MSET S2)
{
	if ((*S2.begin()).ty() != Ordinal_pair)
	{
		std::cout << "this is not a directed graph!" << std::endl;
		return Graphs();
	}
	return Graphs(v, S2);
}

inline unsigned int Graphs::Associations(Date d, MSET S)
{
	unsigned int t = 0;
	MSET::iterator it = S.begin();
	if (*it == d)
		t++;
	++it;
	if (*it == d)
		t++;
	return t;
}

inline bool Graphs::V_Adjacent(size_t d1, size_t d2)
{
	if (d1 > V_num || d2 > V_num)
	{
		std::cout << "can't find the vertex!" << std::endl;
		return false;
	}

	if (Is_Direct)
	{
		int t = d1 > d2 ? arrey->array[--d1][--d2] : arrey->array[--d2][--d1];
		if (t > 0)
			return true;
		else
			return false;
	}
	else
	{
		if ((arrey->array[--d1][--d2] > 0) || (arrey->array[--d2][--d1]))
			return true;
		else
			return false;
	}
}

inline bool Graphs::E_Adjacent(MSET S1, MSET S2)
{
	MSET::iterator it = S1.begin();
	if (S2.find(*it) != S2.end())
		return true;
	++it;
	if (S2.find(*it) != S2.end())
		return true;

	return false;
}

inline bool Graphs::E_Adjacent(ordinal_pair op1, ordinal_pair op2)
{
	return op1.date2() == op2.date1();
}

inline unsigned int Graphs::link_branch()
{
	set<int> traversaled;
	unsigned int sum = 0;
	for (int i = 0; i < V_num; i++)
		link_branch(i, traversaled, sum);
	return sum;
}

inline void Graphs::link_branch(int d, set<int> &traversaled, unsigned int &sum)
{
	if (traversaled.find(d) != traversaled.end())
		return;
	traversaled.insert(d);
	if (Is_Direct)
	{
	}
	else
	{
		int i;
		for (i = 0; i < d; i++)
		{
			if (arrey->array[d][i] > 0)
			{
				if (traversaled.find(i) == traversaled.end())
				{
					link_branch(i, traversaled, sum);
					return;
				}
			}
		}
		for (; i < V_num; i++)
		{
			if (arrey->array[i][d] > 0)
			{
				if (traversaled.find(i) == traversaled.end())
				{
					link_branch(i, traversaled, sum);
					return;
				}
			}
		}
		sum++;
	}
}

inline void Graphs::print()
{
	if (Is_Direct)
	{
		for (size_t i = 0; i < V_num; i++)
		{
			for (size_t j = 0; j < V_num; j++)
			{
				std::cout << arrey->array[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}
	else
	{
		for (size_t i = 0; i < V_num; i++)
		{
			std::cout << i + 1 << "| ";
			for (size_t j = 0; j <= i; j++)
			{
				std::cout << arrey->array[i][j] << " ";
			}
			std::cout << std::endl;
		}
		std::cout << "---";
		for (int i = 1; i <= V_num; i++)
		{
			std::cout << "--";
		}
		std::cout << std::endl
				  << "   ";
		for (int i = 1; i <= V_num; i++)
		{
			std::cout << i << " ";
		}
	}
}