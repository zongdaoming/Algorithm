
```sh
git init //初始化一个git的本地仓库
 
git add README.md //将我的文件装上武器，准备发射
 
git commit -m “first commit” //第一次发射，我的README.md 宝贝已经成功进入到本地仓库
 
git remote add Ceres your_first_git_address //将第一个git address命名为Ceres
 
git push -u Ceres master //注意咯，我要向远端木星发射了，太远了，一定要用push，很费劲的赶脚
 
//这时，不要动，准备再次将我的README宝贝发射到火星上去，
 
//但是因为我的文件已经存在与本地仓库了，因此我就不需要再多余地commit等，
 
//只需要将另一个远端仓库与本地仓库建立一个连接就可以了
 
git remote add Mars your_second_git_address //将第二个git address命名为Mars
 
git push -u Mars master //再次发射，目标火星上的master分支
```

至此，就将一份代码上传到了两个远端仓库，但是注意你仍然时只有一个本地仓库哦

补充：  

在用 git push -u Ceres master 时也要注意这里master是你要上传的分支名称，如果你当前所位于的分支不叫master



---------------------------------------


一、开发分支（dev）上的代码达到上线的标准后，要合并到 master 分支
```shell
git checkout dev
git pull
git checkout master
git merge dev
git push -u origin master
```

二、当master代码改动了，需要更新开发分支（dev）上的代码

```shell
git checkout master 
git pull 
git checkout dev
git merge master 
git push -u origin dev
```


# 三、git remote 删除添加的远程地址
```shell
git remote add origin git@github.com/name/xxx.git
```
查看本地添加了那些远程地址
```cpp
git remote -v
```
删除本地指定的远程地址
```cpp
git remote remove origin // 删除即可
```
