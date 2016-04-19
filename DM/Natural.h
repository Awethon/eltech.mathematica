#pragma once
#include <vector>
using namespace std;

class Natural {
protected:
	vector<int8_t> v_N;
	unsigned int vsize;
public:
	Natural();
	Natural(string);

	unsigned short getDigit(unsigned long long) const;
	unsigned long long getSize() const;

	void resize(unsigned long long);

	static int COM_NN_D(const Natural&, const Natural&);
	static bool NZER_N_B(const Natural&);
	static Natural ADD_1N_N(Natural);
	static Natural ADD_NN_N(Natural, Natural);
	static Natural SUB_NN_N(Natural, Natural);
	static Natural MUL_ND_N(const Natural&, int);
	static Natural MUL_Nk_N(const Natural&, int);
	static Natural MUL_NN_N(const Natural&, const Natural&);
	static Natural SUB_NDN_N(const Natural&, int, const Natural&);
	static Natural DIV_NN_Dk(const Natural&, const Natural&);
	static Natural DIV_NN_N(const Natural&, const Natural&);
	static Natural MOD_NN_N(const Natural&, const Natural&);
	static Natural GCF_NN_N(Natural, Natural);
	static Natural LCM_NN_N(const Natural&, const Natural&);
};
