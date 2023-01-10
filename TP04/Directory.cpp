#include <iostream>
#include <string>
#include <vector>
#include <ctime>



using namespace std;

class File
{
	protected:
		std::string name;
		std::string location;
		std::string permission;
		std::time_t date;

	public:
		File()
		{
			string a;
			cout <<"name of the file\n";
			cin >> a;
			set_name(a);
			location= "/home";//location
			permission = "rw-rw-rw-";//auto
			date = time(0);// auto
		}

		string get_name()
		{
			return name;
		}
	
		void set_name(string a)
		{
			name=a;
		}

		void set_location(string a)
		{
			location=a;
			return;
		}
		string get_location()
		{
			return location;
		}
	

	friend class Shell;
};

class TextFile : public File
{

	public :
		friend class Directory ;
	
};


class ExecFile : public TextFile
{
	bool flag;

};

class Directory : public File
{
	private:
		Directory* parent;
		std::vector <Directory> sub_directories;
		std::vector <TextFile> sub_textFiles;
		std::vector <ExecFile> sub_execFiles;
	
	public:

	Directory* get_parent()
	{
		return parent;
	}
	void set_parent(Directory* X)
	{
		parent=X;

	}
	
	std::vector <Directory> get_sub_dir()
	{
		return sub_directories;
	}
	void set_sub_dir(std::vector <Directory> L)
	{
		sub_directories=L;
	}

	std::vector <TextFile> get_sub_fl()
	{
		return sub_textFiles;
	}
	void set_sub_fl(std::vector <TextFile> L)
	{
		sub_textFiles=L;
	}
	std::vector <ExecFile> get_sub_fex()
	{
		return sub_execFiles;
	}
	void set_sub_fex(std::vector <ExecFile> L)
	{
		sub_execFiles=L;
	}
	friend class File;
	friend Directory mkdir (string nom, Directory* current);

};



class Shell
{
	private:
		Directory ROOTDIR;
		Directory BINDIR;

	public :
	
		Shell()
		{
			set_rootdir_name("home");
			set_bindir_name("bin");
			set_root_dir_loc("/");
		}
		void set_rootdir_name(string a)
		{
			ROOTDIR.set_name(a);
		}
		void set_bindir_name(string a)
		{
			BINDIR.set_name(a);
		}
		void set_root_dir_loc(string a)
		{
			ROOTDIR.set_location(a);
		}


		Directory* get_rootdir()
		{
			return &ROOTDIR;
		}

		Directory* get_bindir()
		{
			return &BINDIR;
		}
	
		friend class Directory;
};




template <typename S>
ostream& operator<<(ostream& os, 
                   const vector<S>& vector)
{
    for (auto element : vector)
	{
        os << element.get_name() << " ";
    }
    return os;
}


Directory mkdir (string nom, Directory* current)
{

	Directory dir;
	
	dir.set_name(nom);
	dir.set_location(current->get_location() + "/" + current->get_name());
	dir.set_parent(current);

	std::vector <Directory> C=current->get_sub_dir();
	C.push_back(dir);
	current->set_sub_dir(C);
	return dir;
}

void ls(Directory*  current)
{
	
	std::cout<< current->get_sub_dir();
	cout<< "\n";
	std::cout<< current->get_sub_fex();
	cout<< "\n";
	std::cout<< current->get_sub_fl();
	return;
}

Directory* cd(Directory* current, string Destination)
{
	vector <Directory> L=current->get_sub_dir();
	for (int i=0;i<L.size();i++)
	{
		if(L[i].get_name()==Destination)
			return &L[i];
		else
		{
			cout << "No such Directory in the current directory";
			return NULL;
		}
	}
}


string find(string file_name, Directory* D)
{
	std::vector <Directory> V=D->get_sub_dir();
	std::vector <TextFile> W=D->get_sub_fl();
	std::vector <ExecFile> X=D->get_sub_fex();
	int i;

	for(i=0;i<W.size();i++)
	{
		if (W[i].get_name()==file_name)
		{
			return W[i].get_location();
		}
	}

	for(i=0;i<X.size();i++)
	{
		if (X[i].get_name()==file_name)
		{
			return X[i].get_location();
		}
	}

	for(i==0;i<V.size();i++)
	{
		if(V[i].get_name()==file_name)
		{
			return V[i].get_location();
		}
	}

	for(i==0;i<V.size();i++)
	{
		return find(file_name,&V[i]);
	}
	return "!!!Not Found!!!";
}

int rm(string file_name, Directory* D)
{

	std::vector <Directory> V=D->get_sub_dir();
	std::vector <TextFile> W=D->get_sub_fl();
	std::vector <ExecFile> X=D->get_sub_fex();
	int i;
	int s=0;


	for(i=0;i<W.size();i++)
	{
		if (W[i].get_name()==file_name)
		{
			s=1;
			W.erase(W.begin() + i);
			D->set_sub_fl(W);
			return 1;
		}
	}


	for(i=0;i<X.size();i++)
	{
		if (X[i].get_name()==file_name)
		{
			s=1;
			X.erase(X.begin() + i);
			D->set_sub_fex(X);
			return 1;
		}
	}


	for(i==0;i<V.size();i++)
	{
		
		if (V[i].get_name()==file_name)
		{
			s=1;
			V.erase(V.begin() + i);
			D->set_sub_dir(V);
			return 1;
		}
	}


	for(i==0;i<V.size();i++)
	{	
		rm(file_name,&V[i]);
	}
	
	if(s==0)
		return 0;
	else 
		return 1;
}


    

int main()
{

    Shell SHELL;
    Directory* CURRENT=SHELL.get_rootdir();
 

    while(0==0)
    {
        string file;
        string command;
        cout << "\ncommand: ";
        cin >>command;
        if (command=="quit")
            exit(0);
        if(command=="ls")
                ls(CURRENT);
        else
        {
        cout << "\nfile: ";
        cin >>file;
        
    
       
        if (command=="mkdir")
            Directory dir=mkdir(file,CURRENT);
        else
        {
                if(command=="cd")
                    CURRENT=cd(CURRENT,file);
                else
                {
                    if(command=="find")
                        cout << find(file,CURRENT);
                        else
                        {
                            if(command=="rm")
                            {
                                int z;
                                z=rm(file,CURRENT);
                                std::cout << "The program finished with returning value: " << z;
                                std::cout<< "\nNOTE: 1 means file deleted, 0 not found in the first place\n";
                            }
                        }
                }
            }
        }
    }
    
    return 0;
}
