#include <iostream>

#include <vector>
#include "point.h"
#include "lof.h"
#include "tinystr.h"
#include "tinyxml.h"
#include "iomanip"

using namespace std;
using namespace LOF;
using namespace matplot;


bool ReadXml(std::string m_xmlpath,
	std::vector<unsigned int>& pickpoints,
	std::map<int, double>& map_long,
	std::map<int, double>& map_lan)
{
	//读取xml文件中的参数值
	TiXmlDocument* Document = new TiXmlDocument();
	if (!Document->LoadFile(m_xmlpath.c_str()))
	{
		std::cout << "无法加载xml文件！" << std::endl;
		std::cin.get();
		return false;
	}
	TiXmlElement* RootElement = Document->RootElement();		//根目录

	TiXmlElement* NextElement = RootElement->FirstChildElement();		//根目录下的第一个节点层

	while (NextElement != NULL)		//判断有没有读完
	{
		

		if (NextElement->ValueTStr() == "pickpoint")		//读到object节点
		{
			TiXmlElement* BoxElement = NextElement->FirstChildElement();
			while (BoxElement != nullptr)
			{
				unsigned int point = atof(BoxElement->GetText());
				pickpoints.push_back(point);
				BoxElement = BoxElement->NextSiblingElement();
			}
		}
	
		if (NextElement->ValueTStr() == "gps")
		{
			TiXmlElement* BoxElement = NextElement->FirstChildElement();
			std::vector<double> longs, lans;
			while (BoxElement != nullptr)
			{
				std::string gps = BoxElement->GetText();
				double gps_d = atof(gps.c_str());
				if (BoxElement->ValueTStr() == "lon")
				{
					longs.push_back(gps_d);
				}
				else
				{
					lans.push_back(gps_d);
				}
				BoxElement = BoxElement->NextSiblingElement();
			}

			for (int i = 0; i < longs.size(); ++i)
			{
				map_long[i + 1] = longs[i];
			}
			for (int k = 0; k < lans.size(); ++k)
			{
				map_lan[k + 1] = lans[k];
			}
		}

		NextElement = NextElement->NextSiblingElement();
	}


	delete Document;
	std::cout << "完成xml的读取" << std::endl;
	return true;
}

void test(){

	// 读取数据
	
	std::string path = "input.xml";
	std::vector<unsigned int> pickpoints;
	std::map<int, double> map_long;
	std::map<int, double> map_lan;
	ReadXml(path, pickpoints, map_long, map_lan);
	vector<CPoint> instances;
	float colors[3] = { 0 };


	for (int i = 0; i < map_long.size(); i++)
	{
		instances.push_back(CPoint(colors, 2, map_long[i+1], map_lan[i+1]));
	}



	
	/*instances.push_back(CPoint(colors, 2, -4.8447532242074978, -5.6869538132901658));
	instances.push_back(CPoint(colors,  2, 1.7265577109364076, -2.5446963280374302));
	instances.push_back(CPoint(colors, 2, -1.9885982441038819   ,  1.705719643962865));
	instances.push_back(CPoint(colors, 2,  -1.999050026772494    ,  -4.0367551415711844   ));
	instances.push_back(CPoint(colors, 2, -2.0550860126898964   ,  -3.6247409893236426   ));
	instances.push_back(CPoint(colors, 2,  -1.4456945632547327   ,  -3.7669258809535102   ));
	instances.push_back(CPoint(colors, 2,  -4.6676062022635554   ,  1.4925324371089148    ));
	instances.push_back(CPoint(colors, 2,  -3.6526420667796877   ,  -3.5582661345085662   ));
	instances.push_back(CPoint(colors, 2,  6.4551493172954029    ,  -0.45434966683144573  ));
	instances.push_back(CPoint(colors, 2,  -0.56730591589443669  ,  -5.5859532963153349   ));
	instances.push_back(CPoint(colors, 2,  -5.1400897823762239   ,  -1.3359248994019064   ));
	instances.push_back(CPoint(colors, 2,  5.2586932439960243    ,  0.032431285797532586  ));
	instances.push_back(CPoint(colors, 2,  6.3610915734502838    ,  -0.99059648246991894  ));
	instances.push_back(CPoint(colors, 2,  -0.31086913190231447  ,  -2.8352818694180644   ));
	instances.push_back(CPoint(colors, 2,  1.2288582719783967    ,  -1.1362795178325829   ));
	instances.push_back(CPoint(colors, 2,  -0.17986204466346614  ,  -0.32813130288006365  ));
	instances.push_back(CPoint(colors, 2,  2.2532002509929216    ,  -0.5142311840491649   ));
	instances.push_back(CPoint(colors, 2,  -0.75397166138399296  ,  2.2465141276038754    ));
	instances.push_back(CPoint(colors, 2,  1.9382517648161239    ,  -1.7276112460593251   ));
	instances.push_back(CPoint(colors, 2,  1.6809250808549676    ,  -2.3433636210337503   ));
	instances.push_back(CPoint(colors, 2,  0.68466572523884783   ,  1.4374914487477481    ));
	instances.push_back(CPoint(colors, 2,  2.0032364431791514    ,  -2.9191062023123635   ));
	instances.push_back(CPoint(colors, 2,  -1.7565895138024741   ,  0.96995712544043267   ));
	instances.push_back(CPoint(colors, 2,  3.3809644295064505    ,  6.7497121359292684    ));
	instances.push_back(CPoint(colors, 2,  -4.2764152718650896   ,  5.6551328734397766    ));
	instances.push_back(CPoint(colors, 2,  -3.6347215445083019   ,  -0.85149861984875741  ));
	instances.push_back(CPoint(colors, 2,  -5.6249411288060385   ,  -3.9251965527768755   ));
	instances.push_back(CPoint(colors, 2,  4.6033708001912093    ,  1.3375110154658127    ));
	instances.push_back(CPoint(colors, 2,  -0.685421751407983    ,  -0.73115552984211407  ));
	instances.push_back(CPoint(colors, 2,  -2.3744241805625044   ,  1.3443896265777866    ));*/

//	LOF lof(instances, true);

	vector<outlier>out;
	out = GetOutliers(6, instances);
	vector<double>xxt,yyt;
	vector<std::string> v_texts;
	char outstr[256];
	

	vector<double> ox, oy;
	for (int k=0;k<instances.size();k++)
	{
		ox.push_back(instances[k].GetValue(0));
		oy.push_back(instances[k].GetValue(1));
		float firstR = instances[k].Getcolor()[0];
		//printf("color's first element:%f \n", firstR);
		if (firstR!=0.0f)
		{
			sprintf(outstr, "Out:%dth", k+1);
			v_texts.push_back(outstr);
			xxt.push_back(instances[k].GetValue(0));
			yyt.push_back(instances[k].GetValue(1));
		}
	}

	for (int i = 0; i < out.size(); i++)
	{

		cout << "原始 标定点Index:" << out.at(i).index+1 << std::endl;
		cout << setiosflags(ios::fixed) << setprecision(20) << out.at(i).lof << " ( ";
		cout << setiosflags(ios::fixed) << setprecision(20) << out.at(i).instance.GetValue(0) << " , ";
		cout << setiosflags(ios::fixed) << setprecision(20) << out.at(i).instance.GetValue(1) << " ) " << endl;
	}
	
	
	// 3D scatter3 example
	/*auto [x, y, z] = generate_data();
	scatter3(x, y, z);*/

	// 打印离群点
	//auto c = linspace(106.8283, 106.8289, ox.size());
	auto ll = scatter(ox, oy);
	ll->marker_color({ 0.f,0.f,0.8f });
	ll->marker_face_color({ 0.f,0.8f,0.0f });
	text(xxt, yyt, v_texts)->color("red").font_size(14);
	title("Whole points");
	show();

}



void main(){
	test();
	system("pause");
}