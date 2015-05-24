#ifndef QUERYANALYSIS_H
#define QUERYANALYSIS_H

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class CQueryAnalysis
{
    public:
        struct SData{
            string m_str;
            int m_iCnt;
            SData(){
                m_iCnt = 0;
            }
        };
    public:
        //待分析串输入解构定义
        typedef vector<string> CArrayString;

        //返回结果的数据结构定义
        typedef vector<SData *> CArrayData;

        /* 返回的结果数据
        * string key为pm输入的每个query
        * CArrayData 为结果的集合，按照m_iCnt从大到小排序， 每个元素是SData ,其中m_str是和key相似的串， m_iCnt是该相似串出现的次数
         */
        typedef map<string, CArrayData> CMapResult;
    public:
        CQueryAnalysis(void);

        ~CQueryAnalysis(void);

        /*  需要参赛选手实现 初始化
        * const char* pStrPath 待分析文件路径 "querys.dat"
        * string &strErr       错误信息
        * return  bool 是否成功
         */
        bool Init(const char* pStrPath, string &strErr);

        /* 需要参赛选手实现 输入query分析
        * CArrayString &arrQuery pm输入query集合
        * CMapResult &mRes  返回结果 
        * int iDistance 编辑距离默认为2
        * string &strErr 错误信息
         */
        int AnalysisQuery(CArrayString &arrQuery, CMapResult &mRes, int iDistance, string &strErr);

        /* 需要参赛选手实现 反初始化文件
        * string &strErr
         */
        bool Uninit(string &strErr);

    protected:
        typedef map<string, SData*> CMapStringToSData;

        struct SWord{
            char *m_pWord;
            int m_iSize;
            SWord(){
                Clear();
            }
            void Clear(){
                m_pWord = NULL;
                m_iSize = 0;
            }
        };

        typedef vector<SWord> CArraySWord;
    protected:
        bool CompareString(string &strInput, string &strQuery, int iDistance);
        bool CheckQuery(string &str, int iWordCnt, CArraySWord &arrWord, int iDistance);
        bool GetWord(string &str, CArraySWord &arrRes);
        int CheckChar(const char *pStr, int iSize);

    protected:
        ifstream m_fRead;
        CMapStringToSData m_mCnt;
};

bool CmpSData(const CQueryAnalysis::SData* pData1, const CQueryAnalysis::SData* pData2){
    return pData1->m_iCnt > pData2->m_iCnt;
}

CQueryAnalysis::CQueryAnalysis(void){
}

CQueryAnalysis::~CQueryAnalysis(void){
}
int Min(int a,int b,int c)
{
    return c<(a>b?b:a)?c:(a>b?b:a);
}

bool CQueryAnalysis::Init(const char* pStrPath, string &strErr){
    bool bOk = false;
    strErr = "";
    m_fRead.open(pStrPath);
    if(m_fRead){
        bOk = true;
    }
    return bOk;
}

int CQueryAnalysis::AnalysisQuery(CArrayString &arrQuery, CMapResult &mRes, int iDistance, string &strErr){
    int iRes = 0;
    strErr = "";
    mRes.clear();
    string strLine;
    while(getline(m_fRead, strLine)){
        //trim	
        int iSize = arrQuery.size();
        if(m_mCnt.find(strLine) == m_mCnt.end()){		
            for(int i = 0; i < iSize; i++){
                if(CompareString(arrQuery[i], strLine, iDistance)){
                    SData* pData = new SData;
                    pData->m_str = strLine;
                    pData->m_iCnt = 1; 
                    if(mRes.find(arrQuery[i]) == mRes.end()){
                        CArrayData arrDataTmp;
                        arrDataTmp.push_back(pData);
                        mRes.insert(make_pair(arrQuery[i], arrDataTmp));
                    }else{
                        mRes[arrQuery[i]].push_back(pData);
                    }
                    m_mCnt.insert(make_pair(strLine, pData));
                }
            }
        }else{
            m_mCnt[strLine]->m_iCnt++;
        }
    }
    CMapResult::iterator itRes = mRes.begin(); 
    CArrayData arrData;
    for(; itRes != mRes.end(); ++itRes){
        std::sort(itRes->second.begin(), itRes->second.end(), CmpSData);
    }
    return iRes;
}


bool CQueryAnalysis::CompareString(string &strInput, string &strQuery, int iDistance){
    bool bOk = false;
    CArraySWord arrInput, arrQuery; 
    SWord sWord;
    GetWord(strInput, arrInput);
    GetWord(strQuery, arrQuery);

    int nTab[256][256] = {0};
    int m = arrInput.size(),
        n = arrQuery.size(),
        i = 0, j = 0;

    for(i = 0; i<= m; ++i){
        nTab[i][0] = i;
    }
    for(j = 0; j <= n; ++j){
        nTab[0][j] = j;
    }
    int nCost = 0;
    for(i = 1;i <= m; ++i){
        for(j=1;j<=n;++j){
            if(arrInput[i-1].m_iSize == arrQuery[j-1].m_iSize && memcmp(arrInput[i-1].m_pWord, arrQuery[j-1].m_pWord, arrInput[i-1].m_iSize) == 0){
                nCost = 0;
            }else{
                nCost = 1;
            }
            nTab[i][j]= Min(nTab[i-1][j-1] + nCost, nTab[i-1][j] + 1, nTab[i][j-1] + 1);
        }
    }
    if(nTab[m][n] <= iDistance){
        bOk = true;
    }

    return bOk;
}

bool CQueryAnalysis::CheckQuery(string &str, int iWordCnt, CArraySWord &arrWord, int iDistance){
    bool bOk = false;
    int iSize = arrWord.size(), iPos = 0, iStrPos = 0, iCnt = 0;
    for(int i = 0; i < iSize ; i++){
        if( (iPos = str.find(string(arrWord[i].m_pWord, arrWord[i].m_iSize), iStrPos)) != string::npos){
            iStrPos = iPos + arrWord[i].m_iSize;
            iCnt++;  
        }
    }
    if(iWordCnt - iCnt <= iDistance){
        bOk = true;
    }
    return bOk;
}

bool CQueryAnalysis::Uninit(string &strErr){
    bool bOk = false;
    strErr = "";
    m_fRead.close();
    return bOk;
}
bool CQueryAnalysis::GetWord(string &str, CArraySWord &arrRes){
    bool bOk = true;
    arrRes.clear();
    char *pStr = const_cast<char *>(str.c_str());
    int iLen = 0, iEnSize = 0, iSize = str.size();
    while((iLen = CheckChar(pStr, iSize)) > 0){
        SWord sWd;
        if(iLen == 1){
            const unsigned char *pStrTmp = (unsigned char *) pStr; 
            if(*pStrTmp >= 'a' && *pStrTmp <= 'z' || *pStrTmp >= 'A' && *pStrTmp <= 'Z' || 
                    *pStrTmp >= '0' && *pStrTmp <= '9'){
                iEnSize++; 
            }else{
                if(iEnSize > 0){
                    sWd.m_pWord = pStr - iEnSize;			
                    sWd.m_iSize = iEnSize;			
                    arrRes.push_back(sWd);
                    iEnSize = 0; 
                }
            }

        }else if(iLen == 2){
            if(iEnSize > 0){
                sWd.m_pWord = pStr - iEnSize;			
                sWd.m_iSize = iEnSize;			
                arrRes.push_back(sWd);
                iEnSize = 0; 
            }
            sWd.m_pWord = pStr;			
            sWd.m_iSize = iLen;			
            arrRes.push_back(sWd);
        }
        pStr += iLen; 
        iSize -= iLen;
    }
    SWord sWd;
    if(iEnSize > 0){
        sWd.m_pWord = pStr - iEnSize;			
        sWd.m_iSize = iEnSize;			
        arrRes.push_back(sWd);
        iEnSize = 0; 
    }
    return bOk;
}

int CQueryAnalysis::CheckChar(const char *Data, int Size){
    const unsigned char   *p = (unsigned char *) Data; 
    if ( p == NULL || Size <= 0 ) 
        return 0;  
    if ( p[0] < 0x81 || p[0] > 0xFE ) 
        return 1; 
    if ( Size < 2 ) 
        return -1; 
    if ( p[1] < 0x30 || p[1] > 0x39 && p[1] < 0x40 || p[1] == 0x7F 
            || p[1] > 0xFE ) 
        return -1; 
    if ( p[1] >= 0x40 ) 
        return 2; 
    if ( Size < 4 ) 
        return -1; 
    if ( p[2] < 0x81 || p[2] > 0xFE ) 
        return -1; 
    if ( p[3] < 0x30 || p[3] > 0x39 ) 
        return -1; 
    return 4; 
}
#endif
