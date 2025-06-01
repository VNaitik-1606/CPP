if ! grep -qxF ".vscode/" .gitignore; then
  echo ".vscode/" >> .gitignore
  git add .gitignore
  echo "✅ Added .vscode/ to .gitignore"
fi

if [ -d ".vscode" ]; then
  git rm -r --cached .vscode 2>/dev/null
fi

echo "📝 Enter commit message:"
read msg

git add .
git commit -m "$msg"
git push
