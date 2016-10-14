#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;
using namespace boost::gregorian;

int totalIncome = 0;
int totalPayment = 0;

list<string> readRecord();
void writeResult( list<string> &result );
string generateSummary( string &input );
list<string> generateResult( list<string> &records );

int main()
{
    list<string> records = readRecord();
    list<string> result = generateResult(records);
    writeResult(result);

    return 0;
}

list<string> readRecord()
{
    list<string> records;

    ifstream in( "input/input.csv", ios::in );

    if ( in.is_open() ) {
        string buffer;
        while ( getline( in, buffer ) ) {
            records.push_back(buffer);
        }
    }

    in.close();

    return records;
}

void writeResult( list<string> &result )
{
    ofstream out( "output/output.csv", ios::out | ios::trunc );

    out << "[Summary]" << endl << endl;
    cout << "[Summary]" << endl << endl;
    for( list<string>::iterator it=result.begin(); it!=result.end(); ++it ) {
        out << *it << endl;
        cout << *it << endl;
    }
    out << endl;
    out << "Total Income:" << totalIncome << endl;
    out << "Total Payment:" << totalPayment << endl;
    out << "Profit:" << totalIncome - totalPayment << endl;
    cout << endl;
    cout << "Total Income:" << totalIncome << endl;
    cout << "Total Payment:" << totalPayment << endl;
    cout << "Profit:" << totalIncome - totalPayment << endl;

    out.close();
}

string generateSummary(string &input)
{
    trim(input);
    vector<string> messages;
    split( messages, input, is_any_of(" ") );

    date d(from_string(messages[0]));

    int weekdayPoint[] = { 9, 12, 18, 20, 22 },
        weekdayPrice[] = { 0, 30, 50, 80, 60 },
        weekendPoint[] = { 9, 12, 18, 22 },
        weekendPrice[] = { 0, 40, 50, 60 };
    int duration, startTime, stopTime;
    int pricePerCourt, levNum;
    int *point, *price;
    vector<string> times;
    split( times, messages[1], is_any_of(":~") );
    stopTime = lexical_cast<int>(times[2]);
    startTime = lexical_cast<int>(times[0]);
    duration = stopTime - startTime;
    if ( d.day_of_week() == 0 || d.day_of_week() == 6 ) {
        levNum = 4;
        point = weekendPoint;
        price = weekendPrice;
    }
    else {
        levNum = 5;
        point = weekdayPoint;
        price = weekdayPrice;
    }
    for ( int i = 0; i < levNum; ++i ) {
        if( startTime <= point[i] ) {
            if ( stopTime <= point[i] )
                pricePerCourt = (stopTime - startTime) * price[i];
            else
                pricePerCourt = (point[i] - startTime) * price[i]
                    + (stopTime - point[i]) * price[i+1] ;
            break;
        }
    }

    stringstream summary;
    int M = lexical_cast<int>(messages[2]);
    int T = M / 6, X = M % 6;
    int income = M * 30, payment, profit;
    if ( T == 0 && X < 4 ) {
        income = 0;
        payment = 0;
    }
    else if ( T == 0 && X >= 4 )    payment = pricePerCourt;
    else if ( T == 1 )              payment = pricePerCourt * 2;
    else if ( ( T == 2 || T == 3 )
                && X >= 4 )         payment = pricePerCourt * ( T + 1);
    else                            payment = pricePerCourt * T;

    totalIncome += income;
    totalPayment += payment;
    summary << messages[0] << " " << messages[1] << " +" << income
        << " -" << payment << " " << income - payment;

    return summary.str();
}

list<string> generateResult( list<string> &records )
{
    list<string> result;
    for ( list<string>::iterator it=records.begin(); it!=records.end(); ++it ) {
        result.push_back( generateSummary( *it ) );
    }

    return result;
}
