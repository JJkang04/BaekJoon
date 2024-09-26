#include <iostream>
#include <string>
#include <vector>
using namespace std;


vector<vector<int>> rotateArray(vector<vector<int>> vec, int& sizeN, int& sizeM,  int caseNum) {
	// 배열의 가로 길이는 sizeM, 세로 길이는 sizeN
	

	if (caseNum == 1) {

		for (int i = 0; i < sizeN / 2; ++i) {
			vector<int>  temp = vec[sizeN - 1 - i];
			vec[sizeN - 1 - i] = vec[i];
			vec[i] = temp;
		}

		return vec;
	}

	else if (caseNum == 2) {

		for (int i = 0; i < sizeM / 2; ++i) {
			vector<int> temp;

			for (int j = 0; j < sizeN; ++j) {
				temp.push_back(vec[j][sizeM - 1 - i]);
			}

			for (int k = 0; k < sizeN; ++k) {
				vec[k][sizeM - 1 - i] = vec[k][i];
				vec[k][i] = temp[k];
			}
		}
		return vec;
	}

	else if (caseNum == 3) {

		vector<vector<int>> resultVec;

		for (int i = 0; i < sizeM; ++i) {
			vector<int> temp;
			for(int  j = sizeN-1; j>=0; --j) {
				temp.push_back(vec[j][i]);
			}

			resultVec.push_back(temp);
		}
		


		return resultVec;

	}

	else if (caseNum == 4) {

		vector<vector<int>> resultVec;

		for (int i = sizeM - 1; i >= 0; --i) {

			vector<int> temp;

			for (int j = 0; j < sizeN; ++j) {
				temp.push_back(vec[j][i]);
			}

			resultVec.push_back(temp);
		}

		return resultVec;

	}

	else if (caseNum == 5) {

		vector<vector<int>> vec1(sizeN / 2, vector<int>(sizeM / 2,0));
		vector<vector<int>> vec2(sizeN / 2, vector<int>(sizeM / 2,0));
		vector<vector<int>> vec3(sizeN / 2, vector<int>(sizeM / 2,0));
		vector<vector<int>> vec4(sizeN / 2, vector<int>(sizeM / 2,0));

		for (int i = 0; i < sizeN; ++i) {
			for (int j = 0; j < sizeM; ++j) {
				
				if (i < sizeN / 2 && j < sizeM / 2) {
					vec1[i][j] = vec[i][j];
				}
				
				else if (i < sizeN / 2 && j >= sizeM / 2) {
					vec2[i][j-sizeM/2] = vec[i][j];
				}
				
				else if (i >= sizeN / 2 && j >= sizeM / 2) {
					vec3[i-sizeN/2][j-sizeM/2] = vec[i][j];
				}
				
				else {
					vec4[i-sizeN/2][j] = vec[i][j];
				}
			}
		}

		vector<vector<int>> tmp = vec1;

		vec1 = vec4;
		vec4 = vec3;
		vec3 = vec2;
		vec2 = tmp;

		for (int i = 0; i < sizeN; ++i) {
			for (int j = 0; j < sizeM; ++j) {
				
				if (i < sizeN / 2 && j < sizeM / 2) {
					vec[i][j] = vec1[i][j];
				}
				else if (i < sizeN / 2 && j >= sizeM / 2) {
					vec[i][j] = vec2[i][j-sizeM/2];
				}
				else if (i >= sizeN / 2 && j >= sizeM / 2) {
					vec[i][j] = vec3[i-sizeN/2][j-sizeM/2];
				}
				else {
					vec[i][j] = vec4[i-sizeN/2][j];
				}
			}
		}
		return vec;
	}

	else if (caseNum == 6) {

		vector<vector<int>> vec1(sizeN / 2, vector<int>(sizeM / 2, 0));
		vector<vector<int>> vec2(sizeN / 2, vector<int>(sizeM / 2, 0));
		vector<vector<int>> vec3(sizeN / 2, vector<int>(sizeM / 2, 0));
		vector<vector<int>> vec4(sizeN / 2, vector<int>(sizeM / 2, 0));

		for (int i = 0; i < sizeN; ++i) {
			for (int j = 0; j < sizeM; ++j) {

				if (i < sizeN / 2 && j < sizeM / 2) {
					vec1[i][j] = vec[i][j];
				}

				else if (i < sizeN / 2 && j >= sizeM / 2) {
					vec2[i][j - sizeM / 2] = vec[i][j];
				}

				else if (i >= sizeN / 2 && j >= sizeM / 2) {
					vec3[i - sizeN / 2][j - sizeM / 2] = vec[i][j];
				}

				else {
					vec4[i - sizeN / 2][j] = vec[i][j];
				}
			}
		}

		vector<vector<int>> tmp = vec4;

		vec4 = vec1;
		vec1 = vec2;
		vec2 = vec3;
		vec3 = tmp;

		for (int i = 0; i < sizeN; ++i) {
			for (int j = 0; j < sizeM; ++j) {

				if (i < sizeN / 2 && j < sizeM / 2) {
					vec[i][j] = vec1[i][j];
				}
				else if (i < sizeN / 2 && j >= sizeM / 2) {
					vec[i][j] = vec2[i][j - sizeM / 2];
				}
				else if (i >= sizeN / 2 && j >= sizeM / 2) {
					vec[i][j] = vec3[i - sizeN / 2][j - sizeM / 2];
				}
				else {
					vec[i][j] = vec4[i - sizeN / 2][j];
				}
			}
		}
		return vec;
	}
}


int main() {

	int n, m, r;

	cin >> n >> m >> r;

	vector<vector<int>> vec;

	for (int i = 0; i < n; ++i) {
		vector<int> v;
		for (int j = 0; j < m; ++j) {
			int k;
			cin >> k;
			v.push_back(k);
		}
		vec.push_back(v);
	}

	vector<vector<int>> newVec;
	
	newVec = vec;

	for (int i = 0; i < r; ++i) {
		int order;
		cin >> order;

		int N = newVec.size();
		int M = newVec.front().size();

		newVec = rotateArray(newVec,N, M, order);
	}

	for (int i = 0; i < newVec.size(); ++i) {
		for (int j = 0; j < newVec.front().size(); ++j) {
			cout << newVec[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
