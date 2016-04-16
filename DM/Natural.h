#pragma once
#include <vector>
#include <string>
using namespace std;

class Natural {
protected:
	vector<int8_t> natural_v;
	unsigned int vsize;
public:
	Natural();

	Natural(string);

	unsigned short getDigit(unsigned int);

	unsigned int getSize();

	void resize(unsigned int);

	static int COM_NN_D(Natural, Natural);

	static bool NZER_N_B(Natural);

	static Natural ADD_1N_N(Natural);

	static Natural ADD_NN_N(Natural, Natural);

	static Natural SUB_NN_N(Natural, Natural);

	static Natural MUL_ND_N(Natural, int);

	static Natural MUL_Nk_N(Natural, int);

	static Natural MUL_NN_N(Natural, Natural);

	static Natural SUB_NDN_N(Natural, int, Natural);

	static Natural DIV_NN_Dk(Natural, Natural);

	static Natural DIV_NN_N(Natural, Natural);

	static Natural MOD_NN_N(Natural, Natural);

	static Natural GCF_NN_N(Natural, Natural);

	static Natural LCM_NN_N(Natural, Natural);

};
