# Google Chrome を用いて local で JavaScript のチェックを行う

`--allow-file-access-from-files` オプションをつけて Chrome を立ち上げれば良い。
AppleScript Editor を用いて（ * は半角スペースを表す）、

``` applescript
do shell script "/Applications/Google*Chrome.app/Contents/MacOS/Google*Chrome --allow-file-access-from-files"
```

これを適当な名前でアプリとして保存する。
以降、このアプリから Chrome を呼び出す。
