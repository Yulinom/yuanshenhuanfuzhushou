# yuanshenhuanfuzhushou
原神换服助手--简单的c实现，文件复制

#### 说明

main.c为代码**源文件**,yuanshenhuanfuzhushou/zhushou/bin/Release  目录下是工具的整体，使用时只需要下载这个目录下的文件和文件夹即可

##### 使用步骤

1.配置原神源文件
  把hf文件夹下的**PCGameSDK.dll**文件放到原神安装目录Genshin Impact\Genshin Impact Game\YuanShen_Data\Plugins下
  ![目录示例](./zhushou/bin/Release/samplepngs/sample1.png)
  
2.运行zhushou.exe文件
  鼠标右键，选择**以管理员身份运行**打开程序
    第一次运行需要输入原神安装目录，以后若没更改过则无需再次输入目录，目录到Genshin Impact即可。
    ![目录示例](./zhushou/bin/Release/samplepngs/sample2.png)
    如若更改了原神目录，需要打开编辑hf文件夹中的exten.txt，把最后的had changed删掉即会重置程序
