#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

string pattern, filename;
int cache[101][101];

void removeTwoAsterisk()
{
	int i;
	for (i = 0; i < pattern.length()-1; i++)
	{
		if (pattern[i] == '*' && pattern[i + 1] == '*')
		{
			pattern = pattern.substr(0, i + 1) + pattern.substr(i + 2, pattern.length() - (i + 2));
			i--;
		}
	}
	
}
bool match(int w, int s)
{
	int &ret = cache[w][s];
	if (ret != -1) return ret;
	int pos = 0;	
	while (pos < filename.size()-s && pos < pattern.size()-w && (pattern[w+pos] == '?' || pattern[w+pos] == filename[s+pos]))
	{
		++pos;		
	}
	if (pos+w == pattern.size()) return ret = ((pos+s) == filename.size()) ;
	if (pattern[w+pos] == '*')
	{
		bool flag=false;
		for (int i = s+pos; i <= filename.size(); i++)
		{
			if (match(w+pos+1, i) == true) 
				flag = true;
		}
		return ret = flag;
	}
	return ret = false;
}
int main()
{
	ifstream in;
	ofstream out;
	in.open("input.txt", ios::in);
	out.open("output.txt", ios::out);
	int C;
	in >> C;
	for (int i = 0; i < C; i++)
	{
		int stringnum;		
		vector<string> files;		
		in >> pattern;
		removeTwoAsterisk();
		in >> stringnum;
		for (int j = 0; j < stringnum; j++)
		{
			memset(cache, -1, sizeof(cache));
			in >> filename;
			if (match(0,0) == 1) files.push_back(filename);
		}
		sort(files.begin(), files.end());
		for (int j = 0; j < files.size(); j++) out << files[j] << endl;
	}

	in.close();
	out.close();
	return 0;
}