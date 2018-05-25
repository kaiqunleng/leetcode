#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int ssum = 0;
        for(auto i :grid){
            for(auto j:i){
                
                ssum += j;                      
            }
            
        }
        if(ssum==0){
            return 0;                    //所有元素为0的情况
        }
        
        
        
        fillRunvector(grid,numofruns,stRun,enRun,rowRun);
        firstPass(stRun,enRun,rowRun,numofruns,runLabels,equivalences);
	    replaceSameLabel(runLabels, equivalences);
        int maxlevel = *max_element(runLabels.begin(), runLabels.end());
        vector<vector<int>>abc(maxlevel);     //存放所有集合最终的所属关系   eg: 1 1 1 1 2 1 2 1 3
	    vector<int>mmmax(maxlevel);
	    for (int i = 1; i <= maxlevel; ++i) {

		    for (int j = 0; j < runLabels.size(); ++j) {
			    if (runLabels[j] == i) {
				    abc[i-1].push_back(j);
			                           }
		                                                }

	    }

	    for (auto i : abc) {
		    int sum = 0;
		    for (auto j : i) {
			   sum = sum + enRun[j] - stRun[j] + 1;
		    }
		    mmmax.push_back(sum);
	   }
	    int finalmax = *max_element(mmmax.begin(),mmmax.end());
        return finalmax;
        
    
        
    }
    
    
    void fillRunvector(   vector<vector<int>>&Image, int&numofruns,vector<int>&stRun,vector<int>&enRun,vector<int>&rowRun) {
	for (int i = 0; i < Image.size(); ++i) {
		int rowData = Image[i][0];
		if (rowData == 1) {
			numofruns++;
			stRun.push_back(0);
			rowRun.push_back(i);
		}
		for (int j = 1; j < Image[0].size(); ++j) {

			if (Image[i][j - 1] == 0 && Image[i][j] == 1) {
				numofruns++;
				stRun.push_back(j);
				rowRun.push_back(i);
			}
			else if (Image[i][j - 1] == 1 && Image[i][j] == 0) {
				enRun.push_back(j - 1);
			}
		}

		if (Image[i][Image[i].size() - 1] == 1) {
			enRun.push_back(Image[i].size()-1);

		}

	}
}
    
    
    void firstPass(vector<int>& stRun, vector<int>& enRun, vector<int>& rowRun, int NumberOfRuns,
	vector<int>& runLabels, vector<pair<int, int>>& equivalences)
{
	runLabels.assign(NumberOfRuns, 0);
	int idxLabel = 1;
	int curRowIdx = 0;
	int firstRunOnCur = 0;
	int firstRunOnPre = 0;
	int lastRunOnPre = -1;
	for (int i = 0; i < NumberOfRuns; i++)
	{
		if (rowRun[i] != curRowIdx)
		{
			curRowIdx = rowRun[i];
			firstRunOnPre = firstRunOnCur;
			lastRunOnPre = i - 1;
			firstRunOnCur = i;

		}
		for (int j = firstRunOnPre; j <= lastRunOnPre; j++)
		{
			if (stRun[i] <= enRun[j] && enRun[i] >= stRun[j] && rowRun[i] == rowRun[j] + 1)
			{
				if (runLabels[i] == 0) // 没有被标号过
					runLabels[i] = runLabels[j];
				else if (runLabels[i] != runLabels[j])// 已经被标号 ,说明至少有2个等价对                   
					equivalences.push_back(make_pair(runLabels[i], runLabels[j])); // 保存等价对
			}
		}
		if (runLabels[i] == 0) // 没有与前一列的任何run重合
		{
			runLabels[i] = idxLabel++;
		}

	}
}
    
    
    
    void replaceSameLabel(vector<int>& runLabels, vector<pair<int, int>>&
	equivalence)
{
	int maxLabel = *max_element(runLabels.begin(), runLabels.end());
	vector<vector<bool>> eqTab(maxLabel, vector<bool>(maxLabel, false));
	vector<pair<int, int>>::iterator vecPairIt = equivalence.begin();
	while (vecPairIt != equivalence.end())
	{
		eqTab[vecPairIt->first - 1][vecPairIt->second - 1] = true;
		eqTab[vecPairIt->second - 1][vecPairIt->first - 1] = true;
		vecPairIt++;
	}
	vector<int> labelFlag(maxLabel, 0);
	vector<vector<int>> equaList;
	vector<int> tempList;

	for (int i = 1; i <= maxLabel; i++)
	{
		if (labelFlag[i - 1])
		{
			continue;
		}
		labelFlag[i - 1] = equaList.size() + 1;
		tempList.push_back(i);
		for (vector<int>::size_type j = 0; j < tempList.size(); j++)
		{
			for (vector<bool>::size_type k = 0; k != eqTab[tempList[j] - 1].size(); k++)
			{
				if (eqTab[tempList[j] - 1][k] && !labelFlag[k])   //必须保证邻接矩阵对应元素为1，且没有被标记过。
				{
					tempList.push_back(k + 1);
					labelFlag[k] = equaList.size() + 1;
				}
			}
		}
		equaList.push_back(tempList);
		tempList.clear();
	}

	for (vector<int>::size_type i = 0; i != runLabels.size(); i++)
	{
		runLabels[i] = labelFlag[runLabels[i] - 1];
	}
}
    
    
    
    int numofruns = 0;
	vector<int>stRun;
	vector<int>enRun;
	vector<int>rowRun;
    vector<int> runLabels;
	vector<pair<int, int>> equivalences;
    
};



int main(){
	
	vector<vector<int>>b;
	vector<int>a = { 1,1,1,0,0,1,1,0,1,1 };
	vector<int>c = { 0,0,1,1,1,1,1,1,1,0 };
	vector<int>d = { 1,1,0,0,1,1,0,0,0,0 };
	vector<int>e = {1,1,1,0,1,1,1,0,1,1};
	b = { a ,c,d,e };
	
	
	Solution aa;
	int maxarea = aa.maxAreaOfIsland(b);
	cout<<maxarea;	
	
	
	
}
