#include<bits/stdc++.h>
using namespace std;
string xor1(string a, string b)
{
	
	string result = "";
	
	int n = b.length();
	for(int i = 1; i < n; i++)
	{
		if (a[i] == b[i])
			result += "0";
		else
			result += "1";
	}
	return result;
}

string mod2div(string divident, string divisor)
{
	
	// Number of bits to be XORed at a time.
	int pick = divisor.length();
	
	// Slicing the divident to appropriate
	// length for particular step
	string tmp = divident.substr(0, pick);
	
	int n = divident.length();
	
	while (pick < n)
	{
		if (tmp[0] == '1')
		
			// Replace the divident by the result
			// of XOR and pull 1 bit down
			tmp = xor1(divisor, tmp) + divident[pick];
		else
		
			
			tmp = xor1(std::string(pick, '0'), tmp) +
				divident[pick];
				
		// Increment pick to move further
		pick += 1;
	}
	
	
	if (tmp[0] == '1')
		tmp = xor1(divisor, tmp);
	else
		tmp = xor1(std::string(pick, '0'), tmp);
		
	return tmp;
}

void encodeData(string data, string key)
{
	int l_key = key.length();
	
	// Appends n-1 zeroes at end of data
	string appended_data = (data +
							std::string(
								l_key - 1, '0'));
	
	string remainder = mod2div(appended_data, key);
	
	// Append remainder in the original data
	string codeword = data + remainder;
	cout << "Remainder : "
		<< remainder << "\n";
	cout << "Encoded Data (Data + Remainder) :"
		<< codeword << "\n";
}
void recieverdata(string encodeData,string key)
{
	int l_key = key.length();
	string appended_data = (data + 
	                        std::string(
								l_key - 1, '0'));
	
	string remainder = mod2div(appended_data, key);
}

int main()
{
	string data = "";
	string key = "";

    cout<< "enter Data";
	cin>>data;

	cout<< "enter Key";
	cin>>key;
	
	encodeData(data, key);


	cout<<"ennnter encoded data";
	cin>> recieverdata;
	
	return 0;
}


