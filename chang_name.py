import os
for file in os.listdir('.'):
    if file[-2:] == 'vs' or file[-2:] =='py':
        continue #过滤掉改名字的文件
    # 每隔180个图片分成一类进行名字的修改   名字的形式0_00001.jpg
    #name = file.replace(' ','')
    label = int(file[:-4]) // 180
    name =file[:-4]   # 去掉后缀
    new_name =str(label)+'_'+((5-len(name))*'0')+name+'.jpg' # 
    os.rename(file ,new_name)
