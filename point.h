#ifndef POINT_H
#define POINT_H

#include <stdarg.h>
#include <vector>
#include<exception>
#include <matplot/matplot.h>

namespace LOF{
	class CPoint
		/* nά�����
		*/
	{
	private:
		std::vector<double> coordinate;	//����ֵ
		int dimension;					//ά��
		float m_colors[3];
	public:
		CPoint(float color[3], int dime, ...);	// ����ֵ��ʼ��
		~CPoint();

		void SetValue(int, double);	//�޸�ָ���±��ֵ
		double GetValue(int);	//�õ�ָ���±��ֵ
		int GetDimension();		//�õ�ά��
		void Setcolor(float color[3]);
		float* Getcolor();

	};

	bool IsSame(CPoint, CPoint);	//�ж��Ƿ���ͬ

	double DistEuclidean(CPoint, CPoint);
}
#endif