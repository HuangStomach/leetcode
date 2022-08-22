# 194. 转置文件
# 给定一个文件 file.txt，转置它的内容。
# 你可以假设每行列数相同，并且每个字段由 ' ' 分隔。

# 获取第一行，然后用wc来获取列数
COLS=`head -1 file.txt | wc -w`
# 使用awk依次去输出文件的每一列的参数，然后用xargs做转置
for (( i = 1; i <= $COLS; i++ )); do
    # 这里col就是在代码里要替换的参数，而它等于$i
    awk -v col=$i '{print $col}' file.txt | xargs
done