#include "testlib.h"
#include <bits/stdc++.h>
using namespace std;

FILE *inFile;
FILE *outFile;
FILE *ansFile;
FILE *scoreFile;
FILE *infoFile;
double score;
bool swap_flag;

void registerTestlib()
{
	__testlib_ensuresPreconditions();

	testlibMode = _checker;
	__testlib_set_binary(stdin);

	inf.init(inFile, _input);
	ouf.init(outFile, _output);
	ans.init(ansFile, _answer);
}

void ret(double result, const char *info)
{
	if (swap_flag)
		fprintf(infoFile, "%s\n", info); //Arbiter only allow to read EXACTLY one line info, no less and no more, and must BEFORE score
	fprintf(scoreFile, "%.6f\n", result * score);
	if (!swap_flag)
		fprintf(infoFile, "%s\n", info);

	// for testlib
	if (result == 0)
		quit(_wa, info);
	else
		quit(_ok, info);
}

int main(int argc, char **argv)
{
	//You'd better not change this swith block
	switch (argc)
	{
	case 0: //LOJ
		inFile = fopen("input", "r");
		outFile = fopen("user_out", "r");
		ansFile = fopen("answer", "r");
		scoreFile = stdout;
		infoFile = stderr;
		score = 100;
		break;
	case 4: //Arbiter
		inFile = fopen(argv[1], "r");
		outFile = fopen(argv[2], "r");
		ansFile = fopen(argv[3], "r");
		scoreFile = infoFile = fopen("/tmp/_eval.score", "w");
		score = 10;
		swap_flag = true;
		break;
	case 5:
		if (strcmp(argv[4], "THUOJ") == 0)
		{ //Tsinghua OJ(OJ for DSA course)
			inFile = fopen(argv[1], "r");
			outFile = fopen(argv[3], "r");
			ansFile = fopen(argv[2], "r");
			scoreFile = stdout;
			infoFile = stdout;
			score = 100;
		}
		else
		{ //Tsinsen OJ
			inFile = fopen(argv[1], "r");
			outFile = fopen(argv[2], "r");
			ansFile = fopen(argv[3], "r");
			scoreFile = fopen(argv[4], "w");
			infoFile = fopen("tmp", "w"); //Tsinsen doesn't use this file
			score = 1;
		}
		break;
	case 7: //Lemon and TUOJ
		inFile = fopen(argv[1], "r");
		outFile = fopen(argv[2], "r");
		ansFile = fopen(argv[3], "r");
		FILE *fs = fopen(argv[4], "r");
		if (fs)
			fscanf(fs, "%lf", &score); //Current TUOJ
		else
			sscanf(argv[4], "%lf", &score); //Lemon and future TUOJ
		scoreFile = fopen(argv[5], "w");
		infoFile = fopen(argv[6], "w");
		break;
	}

	registerTestlib();

	// format checking
	string ans_pred = ans.readString();
	if (ouf.readString() != ans_pred)
		ret(0, "Incorrect Yes/No.");
	if (ans_pred[0] == 'Y')
	{
		int n = inf.readInt(), m = inf.readInt();
		vector<string> chessboard;
		vector<int> count;
		for (int j = 0; j < m; j++)
		{
			int x = inf.readInt();
			count.push_back(x);
		}
		for (int i = 1; i <= n; ++i)
		{
			string chessLine = ouf.readString();
			if (chessLine.size() != m)
				ret(0, "The size of chessboard is wrong.");
			for (int j = 0; j < m; ++j)
				if (chessLine[j] != '0' && chessLine[j] != '1')
					ret(0, "There's a wrong character in the chessboard rather than 0 or 1.");
			chessboard.push_back(chessLine);
		}
		// corretness checking
		for (int i = 0; i < n; ++i)
			for (int j = 1; j < m; ++j)
				if (chessboard[i][j - 1] == '1' && chessboard[i][j] == '1')
					ret(0, "There're two adjacent chesses.");
		for (int i = 1; i < n; ++i)
			for (int j = 0; j < m; ++j)
				if (chessboard[i - 1][j] == '1' && chessboard[i][j] == '1')
					ret(0, "There're two adjacent chesses.");
		for (int j = 0; j < m; j++)
		{
			int c = 0;
			for (int i = 0; i < n; i++)
				c += chessboard[i][j] == '1';
			if (c != count[j])
				ret(0, "Incorrect count.");
		}
	}

	ret(1, "Correct.");
	return 0;
}
