# 1. 将所有修改过的文件和新文件添加到暂存区
git add .

# 2. 获取暂存区中所有文件的路径，并将换行符替换为空格/逗号
# 这里使用 git diff --cached --name-only 获取路径
file_list=$(git diff --cached --name-only | tr '\n' ' ')

# 3. 提交更改，将路径列表作为 commit message
# 注意：如果文件过多，message 可能会非常长，建议截取或作为 body
git commit -m "$file_list"

# 4. 推送到 GitHub (假设分支为 main)
git push origin main