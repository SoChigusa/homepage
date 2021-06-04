# Tax Return 手続き（J1ビザ）

**以下のいかなる記述に関しても責任は負いません（間違っていたら教えて）**

アメリカでは収入のある人はみな確定申告をする必要がある。
収入から多めの税金が引かれていることが多いので、確定申告は実質的に"Tax Return"の手続きであり重要らしい。
毎年 4/15 が Tax Day と定められていて（2021年のみ 5/17）、昨年の収入を報告して確定申告をする。
色々と調べることがあって面倒なことで有名なので、ここでも自分の体験談を備忘録。

- 税金には国に支払う連邦税と州に支払う州税があり、それぞれについて確定申告の手続きが必要。
- 必要な収入証明書類は W-2 ないし Form 1042S （違いがよくわからん）だが、僕の場合は UC Path 上で W-2 がダウンロードできた。
- J1ビザの最初の2年間は[税法上の非居住者](https://www.univis-america.com/post/j1-tax-return#:~:text=J1%20%E3%83%93%E3%82%B6%E4%BF%9D%E6%9C%89%E8%80%85%E3%81%AF,%E8%80%85%E3%81%A8%E3%81%BF%E3%81%AA%E3%81%95%E3%82%8C%E3%81%BE%E3%81%99%E3%80%82&text=%E3%81%BE%E3%81%9F%E3%80%81%E6%BB%9E%E5%9C%A8%E6%97%A5%E6%95%B0%E3%81%AB%E6%8B%98%E3%82%8F%E3%82%89,%E7%BE%A9%E5%8B%99%E4%BB%98%E3%81%91%E3%82%89%E3%82%8C%E3%81%A6%E3%81%8A%E3%82%8A%E3%81%BE%E3%81%99%E3%80%82)？
- [こちらのサイト](http://step0ku.kugi.kyoto-u.ac.jp/~ieda/homepage/nasa/tax.html)にあるように、J1ビザの Research Scholar は2年間、ないし5年間連邦税は免除される様子？

## 連邦税（1年目）

まず、国に支払う連邦税の書類を準備する。
UC Berkeley では [Glacier Tax Prep](https://internationaloffice.berkeley.edu/taxes/tax-prep) (GTP) の利用が可能、なのだが所属がLBNLである関係か、僕の場合は使えなかった。
ので、自費で購入する。＄34。
あとは GTP に必要な情報を入れていく。
一箇所だけ詰まった場所として W-2 の Box 14 に DCP という項目がある。
これは UC の mandatory retirement savings とかいうものらしいが、そもそもこの金額はすでに収入から差し引かれていて、Tax Return には関係のない値である。
Box 14 がこういった additional information を書く場所らしい？
GTP 上では others という項目があってそれを用いると問題なく入力ができた。
入力が完了すると自動的に提出用書類が出来上がる。
今回は非居住者用の書類なので Form 1040-NR と Form 8843。
出力されたインストラクションにしたがってこれを印刷し、署名して日付を記入する。
署名と日付の入った書類は保管用、および州税の確定申告用にコピーを取っておく。
W-2 と確定申告書類を適切な住所に郵送する。

## カリフォルニア州税（1年目）

州税の方は [Sprintax](https://www.sprintax.com/) を使うと楽なので購入、＄32。
先ほど作成した Form 1040-NR を手元において、必要な情報を入力していく。
こちらで詰まったのは Line 1 Sch 1 とかいう表記で、Sch は Schedule の略。
どうやら収入の種類によって Form 1040NR の Schedule ** という別紙を何枚か記入する必要があるらしい。
手元にない Schedule に関しては無視して $0.0 と記入すれば良いと判断した。
こちらも入力が終わると処理に入り、完成した書類をダウンロードできるようになる。
Form 540NR と Form 3853。
インストラクションにしたがって適切な場所にサインし、連邦税の確定申告書類のコピーと W-2 のコピーを添えて正しい住所へ郵送。

## 書類の郵送

ついでに。
郵送先が私書箱だったりするので、悪名高い郵便サービス（UPS）を利用して郵送するしかない（？）様子。
一番安い first-class mail で、紛失等が怖いので追跡サービスの certified mail を付けて送る。
これで 1つあたり $5 くらい。
2020年度の連邦税、およびカリフォルニア州税の送り先は

``` text
Department of the Treasury Internal Revenue Service Austin, TX 73301-0215 USA
```

および

``` text
FRANCHISE TAX BOARD PO BOX 942840 SACRAMENTO, CA 94240-0001 USA
```

〆切 1週間前に郵送するも、連邦税の方が途中で事故ったらしく〆切から数日遅れて到着する。
確か消印の日付が重要だったはずなので、セーフだとは思うが。

## FICA税の返還手続き

[ここ](https://www.wakanacpa.com/Tax/SSTax)に詳しいように、J1ビザでの渡航の1,2年めはFICA税と呼ばれる social security tax および medical tax が免除される。
ところが雇用主がこれを知らないと（あるいは適当だと）、勝手に源泉徴収されてこれらが引かれているときがあるので、その場合は雇用主に文句をつけて取り戻す。
誤って源泉徴収された額は W-2 form の欄 4,6 を見ることでわかる。
ここに non-zero の額が入力されていると、GTP を使用した際に以下のようなメッセージが出る。

``` text
You have indicated that FICA tax (the combination of Social Security and Medicare taxes)
was withheld from your compensation as an employee. As a Nonresident Alien for Tax purposes
who is present in the U.S. as an J-1 Research Scholar, you are NOT required to pay FICA tax
for 2020. FICA tax is different from federal, state or local tax and may not be claimed on
your tax return as a payment or deduction.
Because you are NOT required to pay FICA tax, your employer should refund to you any
amounts shown on your Form W-2, Box 4 or Box 6. When finished with GTP, please contact your
employer’s payroll office (the institution that issued your Form W-2) and ask for a refund
of FICA tax because you qualify for the exemption from FICA tax under Internal Revenue Code
section 3121(b)(19).
If your employer refuses to give you a refund, go to www.irs.gov or click on FAQ above to
print Form 843 and Form 8316. Complete both forms and submit them as a refund request
directly to the IRS; DO NOT include Form 843 or Form 8316 with your tax return.
In the meantime, if you owe federal tax, you must pay it with your federal tax return,
irrespective of any FICA tax refund that may or may not be due to you.
You may wish to print this page for future reference. This information is also available on
the FAQ screen.
```

僕の場合は Medicare tax が少額（$28.13）引かれていたので問い合わせるも、FICA 税の免除が適用されたのが 2020 年の 10月からだ（渡航したのは 9月）と言われて跳ね除けられる。謎。
少額なので面倒になってここで諦める。
