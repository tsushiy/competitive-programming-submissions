#!/bin/zsh

# Gitで管理されていないファイルを削除
if git rev-parse 2> /dev/null; then
  echo "Gitで管理されていないファイルを削除します..."
  git clean -d -x -f
fi

# 空ディレクトリを削除
files=$(find . -type d -empty)
if [[ -n "$files" ]]; then
  echo "空ディレクトリを削除します..."
  echo "$files"
  find . -type d -empty -delete
fi

# デバッグ用ファイルを空にする
: > .input
: > .output
: > test.cpp
: > test.py

echo "Clear Done!!"
