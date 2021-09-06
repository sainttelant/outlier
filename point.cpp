#include "point.h"

LOF::CPoint::CPoint(float color[3],int dime, ...)
{
	dimension = dime;
	if (!coordinate.empty())	// ���ǿգ����vector
		coordinate.clear();

	va_list ap;		// ����һ��va_listָ�������ʲ�����
	va_start(ap, dime);// ��ʼ��ap������ָ���һ�����
	double temp;
	for (int i = 0; i < dime; i++)
	{
		temp = va_arg(ap, double);	// ��ȡһ��double�Ͳ��������� ap ָ����һ������
		coordinate.push_back(temp);	// ������������������
	}
	va_end(ap);
	for (int i =0; i < 3; i++)
	{
		m_colors[i] = color[i];
	}
}

LOF::CPoint::~CPoint()
{
	coordinate.clear();
	memset(m_colors, 0, 3);
}

void LOF::CPoint::SetValue(int index, double value)
/*	�޸�coordinate[index]��ֵ
*/
{
	try
	{
		coordinate.at(index) = value;
	}
	catch (std::exception e)
	{
		printf(e.what());
		printf("\n");
		exit(0);
	}
}

double LOF::CPoint::GetValue(int index)
/*	��ȡcoordinate[index]��ֵ
*/
{
	try
	{
		return coordinate.at(index);
	}
	catch (std::exception e)
	{
		printf(e.what());
		printf("\n");
		exit(0);
	}
}

void LOF::CPoint::Setcolor(float color[3])
{
	for (int i=0; i <3;i++)
	{
		m_colors[i] = color[i];
	}
}

float* LOF::CPoint::Getcolor()
{
	static float tmpcolor[3];
	for (int i =0; i<3;i++)
	{
		tmpcolor[i] = m_colors[i];
	}
	return tmpcolor;
}

int LOF::CPoint::GetDimension(){ return dimension; }

bool LOF::IsSame(CPoint point1, CPoint point2)
{
	if (point1.GetDimension() != point2.GetDimension())
		return false;
	else
	{
		int dimension = point1.GetDimension();
		for (int i = 0; i < dimension; i++)
		{
			if (point1.GetValue(i) != point2.GetValue(i))
				return false;
		}
	}
	return true;
}

double LOF::DistEuclidean(CPoint point1, CPoint point2)
/* ����������ľ���
*/
{
	// check if instances are of same dimension
	if (point1.GetDimension() != point2.GetDimension())
	{
		printf("DistEuclidean error: instances have different dimensions.");
		exit(0);
	}
	else{
		int dimension = point1.GetDimension();
		// init differences vector
		std::vector<double>differences(dimension, 0.0);
		// compute difference for each instance and store it to differences vector
		for (int i = 0; i < dimension; i++)
		{
			differences.at(i) = (double)point1.GetValue(i) - (double)point2.GetValue(i);
		}
		// compute RMSE (root mean squared error)
		double sum = 0;
		for (int i = 0; i < dimension; i++)
		{
			sum += ((double)differences.at(i)*(double)differences.at(i));
		}
		double RMSE = sqrt(sum / (double)dimension);
		
		return RMSE;
	}
}