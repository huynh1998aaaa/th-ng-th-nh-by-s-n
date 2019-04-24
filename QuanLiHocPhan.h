#ifndef Test_h
#define Test_H
#include<string>
#include<iostream>
#include <conio.h>
using namespace std;
class Test
{
	private:
		string MaMon;
		int SoTinChi;
		float HeSo;
		string TenMon;
		int SoGioHoc;
		string DieuKien;
	public:
		Test()
		{
			TenMon="null";
			MaMon="null";
			SoTinChi=0;
			HeSo=0;
			SoGioHoc=0;
			DieuKien="null";
		}
		Test(string mamon, string tenmon, int sotinchi, float heso, int sogiohoc, string dieukien)
		{
			MaMon=mamon;
			TenMon=tenmon;
			SoTinChi=sotinchi;
			if (heso<1)
			{
				HeSo=1;
			}
			else
			{
				HeSo=heso;
			}
			SoGioHoc=sogiohoc;
			DieuKien=dieukien;
		}
		void DatMaMon(string mamon)
		{
			MaMon=mamon;
		}
		void DatSoTinChi(int sotinchi)
		{
			SoTinChi=sotinchi;
		}
		void DatTenMon(string tenmon)
		{
			TenMon=tenmon;
		}
		void DatHeSo(float heso)
		{
			if (heso<1)
			{
				HeSo=1;
			}
			else
			{
				HeSo=heso;
			}
		}
		void DatSoGioHoc (int sogiohoc)
		{
			SoGioHoc=sogiohoc;
		}
		void DatDieuKien(string dieukien)
		{
			DieuKien=dieukien;
		}
		string LayTenMon()
		{
			return TenMon;
		}
		string LayMaMon()
		{
			return MaMon;
		}
		int LaySoTinChi()
		{
			return SoTinChi;
		}
		float LayHeso()
		{
			return HeSo;
		}
		int LayHocPhi()
		{
			return SoTinChi*400000*HeSo;
		}
		int LaySoGioHoc()
		{
			return SoGioHoc;
		}
		string LayDieuKien()
		{
			return DieuKien;
		}

		int n;
		void QuanLi()
		{
			Test a[10];
			string mamon[10];
			string tenmon[10];
			int sotinchi[10];
			float heso[10];
			int sogiohoc[10];
			string dieukien[10];
			
			a[0].DatMaMon("MA342");
			a[0].DatTenMon("Giai tich loi");
			a[0].DatSoTinChi(2);
			a[0].DatHeSo(1.6);
			a[0].DatSoGioHoc(54);
			a[0].DatDieuKien("MA111");
				
			a[1].DatMaMon("MA111");
			a[1].DatTenMon("Giai tich 2");
			a[1].DatSoTinChi(3);
			a[1].DatHeSo(1.6);
			a[1].DatSoGioHoc(54);
			a[1].DatDieuKien("Khong");
				
			a[2].DatMaMon("MI302");
			a[2].DatTenMon("Toi uu hoa");
			a[2].DatSoTinChi(2);
			a[2].DatHeSo(1.7);
			a[2].DatSoGioHoc(36);
			a[2].DatDieuKien("MA111");
				
			for (int i=0;i<3;i++)
			{
				mamon[i]=a[i].LayMaMon();
				tenmon[i]=a[i].LayTenMon();
				sotinchi[i]=a[i].LaySoTinChi();
				heso[i]=a[i].LayHeso();
				sogiohoc[i]=a[i].LaySoGioHoc();
				dieukien[i]=a[i].LayDieuKien();
			}
				
			do
			{
				cout<<"Cac chuc nang:"<<endl;
				cout<<"1: Hien thi danh sach"<<endl;
				cout<<"2: Xoa mon"<<endl;
				cout<<"3: Them mon"<<endl;
				cout<<"4: Tim mon theo so tin chi"<<endl;
				cout<<"5: Tim mon theo ten hoac ma mon"<<endl;
				cout<<"6: Thoat"<<endl;
				cout<<"Moi nhap chuc nang: ";
				cin>>n;
				cout<<endl;
				switch(n)
				{
					case 1:
						{
						for(int i=0;i<3;i++)
							{
								cout<<"Ma mon \t\t:"<<mamon[i]<<endl;
								cout<<"Ten mon \t:"<<tenmon[i]<<endl;
								cout<<"So tin chi \t:"<<sotinchi[i]<<endl;
								cout<<"He so \t\t:"<<heso[i]<<endl;
								cout<<"So gio hoc \t:"<<sogiohoc[i]<<endl;
								cout<<"DK tien quyet\t:"<<dieukien[i]<<endl;
									cout<<"--------------------"<<endl;
							}
							break;
						}				
					case 2:
						{
							cout<<"Moi xoa mon"<<endl;
							break;
						}
					case 3:
						{	
							cout<<"Moi them mon"<<endl;
							break;
						}
					case 4:
						{
							cout<<"Nhap so tin chi cua mon: ";
							int x;
							cin>>x;
							int flag;
							for (int i=0; i<3; i++)
							{
								if(x==sotinchi[i])
								{
									flag=1;
									cout<<tenmon[i]<<endl;
								}
							}
							if (flag!=1)
							{
								cout<<"Khong co mon nao!"<<endl;
							}
							break;
						}
					case 5:
						{
							cout<<"Moi nhap ma mon hoac ten mon: ";
							string x;
							cin>>x;
							int flag;
							for(int i=0; i<3;i++)
							{
								if((int)mamon[i].find(x)>-1||(int)tenmon[i].find(x)>-1)
								{
									flag=1;
									cout<<tenmon[i]<<endl;
								}
							}
							if(flag!=1)
							{
								cout<<"Khong co mon nao!"<<endl;
							}
							break;
						}	
					case 6:
						{
							cout<<"Cam on da su dung!"<<endl;
							cout<<"--------------------"<<endl;
							break;							
						}
					default:
					    {
					          cout << "Moi nhap lai!" <<endl;
					          cout<<"--------------------"<<endl;
				       	}
				}
			}while(n!=6);
		}
		~Test()
		{
		}
};	
#endif
