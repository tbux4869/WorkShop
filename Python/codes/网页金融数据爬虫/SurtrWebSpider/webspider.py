import numpy as np 
import re
import requests as rqs
from bs4 import BeautifulSoup
import traceback

class getStockData:

	def __init__(self):
		return None
	
	def getHTMLText(self,url):
		try:
			r=rqs.get(url)
			r.raise_for_status()
			r.encoding=r.apparent_encoding
			return r.text
	
		except:
			return ""
			
	def getStockList(self,lst,stockURL):
		html=self.getHTMLText(stockURL)
		soup=BeautifulSoup(html, 'html.parser')
		a=soup.find_all('a')
		for i in a:
			#由于html中很多a标签，但有些a标签没有href属性，因此用try，except进行异常处理，遇到这类a标签直接continue跳过
			try: 
				#找a标签里的href属性
				href=i.attrs['href']
				#由于深圳交易所sz开头，上海sh开头，股票数字6位数，因此构建如下正则表达式
				lst.append(re.findall(r"[s][hz]\d{6}", href)[0])
			except:
				continue
				
	def getStockInfo(self,lst, stockURL, fpath):
		count = 0
		for stock in lst:
			#这里这样操作是因为百度股票网址的特殊性：url组成为：gupiao.baidu.com/stock/+股票编号+.html
			url=stockURL+stock+".html"
			html=self.getHTMLText(url)
			try:
				if html=="":
					continue
				infoDict={}
				#结合html具体情形，一块一块地解析，把名称，数值等信息一一保存下来
				soup=BeautifulSoup(html, 'html.parser')
				stockInfo=soup.find('div', attrs={'class':'stock-bets'})
				name=stockInfo.find_all(attrs={'class':'bets-name'})
				#股票名称在bets-name标签内，存入字典，split（）表示股票名称空格后面的部分不需要了
				infoDict.update({'stockName':name.text.spilt()[0]})
				
				keyList=stockInfo.find_all('dt')
				valueList=stockInfo.find_all('dd')
				
				for i in range(len(keyList)):
					key=keyList[i].text
					val=valueList[i].text
					infoDict[key]=val
				#最后把字典数据存入外部文件中	
				with open(fpath, 'a', encoding='utf-8') as f:
					f.write(str(infoDict)+'\n')
					count+=1
					print("\r当前进度: {:.2f}%".format(count*100/len(lst)),end="")
			except:
				count+=1
				print("\r当前进度:{:.2f}%".format(count*100/len(lst)), end="")
				continue
	
	def	run(self):
		#print('Please input a url:\n')
		#stock_list_url = input()
		stock_list_url='http://quote.eastmoney.com/stocklist.html'
		stock_info_url='https://gupiao.baidu.com/stock/'
		#print('Please input a output_file:\n')
		#output_file=input()
		output_file='/home/shadow_raven/MyWorkShop/localWorkShop/Python/网页金融数据爬虫/info.txt'
		slist=[]
		self.getStockList(slist,stock_list_url)
		self.getStockInfo(slist,stock_info_url,output_file)
		
				
if __name__=="__main__":
	test=getStockData()
	test.run()		
				


	
