---
marp: true
paginate: true
backgroundColor: #fff
#backgroundImage: url('https://marp.app/assets/hero-background.svg')
---

# EEIC Vim Meetup

2022年2月21日
by [matsui54](https://github.com/matsui54)

---


## 目次

- 自己紹介
- VimとNeovim
- プラグインの紹介
- なぜVSCodeではなく、Vimを使うのか

---

## 自己紹介

- 松井晴輝(GitHub ハンドルネーム: [matsui54](https://github.com/matsui54))
- Vim歴: 2年弱
- 使っているエディタ: Neovim
- Vimの設定ファイルの行数: 
  2400以上（コメント・空白行除く）
- Vim関係の活動: 
  - 自作プラグイン開発
  - プラグインへのプルリクエストなど
  - 本体にも関わっていきたい...

![bg right:20% 90%](https://avatars.githubusercontent.com/u/63794197?v=4)

[^1]: https://vim-jp.org/vim-users-jp/2009/07/10/Hack-39.html

---

### Vimに抱くイメージ
- 古い
- 不便
- ダサい
- VSCodeでよくね

&rArr; 今日はそのイメージを変えたい...!

![bg right:30% 90%](https://2.bp.blogspot.com/-Lm75_V4O7JY/V3x2OZbmIFI/AAAAAAAA8II/fzLckySfqnk0k7P-_YkSF8aDEBuUBodpQCLcB/s800/job_programmer.png)

---

## VimとNeovim
### Vim
- 互換性重視
- どの環境でも入れやすい
- 一応新機能も追加されているが、なんか微妙...

![bg right:30% 40%](https://www.kaoriya.net/blog/2013/12/06/vimlogo-564x564.png)

---

### Neovim
- モダンな機能がどんどん追加されている
  ex. LSP（VSCodeのような言語機能）, TreeSitter (よりよいシンタックスハイライト)
- Better defaults
- Lua（Vim scriptよりも数十倍速い）という言語で拡張可能（もちろんVim scriptも動く）

![bg right:30% 40%](https://raw.githubusercontent.com/neovim/neovim/master/runtime/nvim.png)

特に理由がなければ、Neovimを使うことをおすすめします。

---

## Pluginの紹介

---

### ファイル検索
- ファジーファインダー
  - [denite.nvim](https://github.com/Shougo/denite.nvim) ddu.vimに開発は移行。設定は難しい。
  - [fzf.vim](https://github.com/junegunn/fzf.vim) 一番有名。
  - [Telescope.nvim](https://github.com/nvim-telescope/telescope.nvim)  Neovim専用

Vimにはファジーファインダーがたくさんあるので、興味のあるかたは[こちらの記事](https://zenn.dev/yutakatay/articles/vim-fuzzy-finder)をどうぞ。

- ファイラー
  - [defx.nvim](https://github.com/Shougo/defx.nvim)
  - [fern.vim](https://github.com/lambdalisue/fern.vim) 初心者におすすめ。

![bg right:35% 90%](./vscode_file.png)

---

## VimでIDE的な機能を実現する

---

### Language Server Protocol (LSP)

昔は、便利な編集機能（定義ジャンプや関数や変数の補完）は言語ごとに実装され、そのツールごとにエディタが対応する必要があった。

LSPはこれらの便利機能をプロトコルとして定義し、エディタはLSPの仕様を実装すればどの言語のLanguage Serverの機能も使えるようになった。

&rArr; Vim/Emacs等でもLSP クライアントを入れればVSCodeの編集機能を使えるように!

![w:600](https://code.visualstudio.com/assets/api/language-extensions/language-server-extension-guide/lsp-languages-editors.png)

<!-- _footer: https://code.visualstudio.com/assets/api/language-extensions/language-server-extension-guide/lsp-languages-editors.png -->


---

### VimのLSPクライアント
- [vim-lsp]() (Neovimではない) Vimでも動く。
- Neovim builtin LSP: Neovimの組み込みLSPクライアント。動作が速いがLuaで設定する必要あり。
- [coc.nvim]() "Make your Vim/Neovim as smart as VSCode."がモットー。
  初心者におすすめ。自動補完機能も持っている、オールインワンプラグイン。
  Nodejsを入れる必要あり。

---

### LSPの機能とデモ
- 診断
- 定義ジャンプ
- 補完（引数・補完候補のドキュメントの表示）
- シンボル一覧
- 関数のヒントの表示（ホバー）
- コードの整形

---

### 自動補完
- [ddc.vim](https://github.com/Shougo/ddc.vim) 最強のカスタマイズ性。Denoを入れる必要あり。
- [coc.nvim](https://github.com/neoclide/coc.nvim) 初心者におすすめ。
- [nvim-cmp](https://github.com/hrsh7th/nvim-cmp) Neovimが使うならおすすめ。

![drop-shadow](ddc.png)

---

### ddc.vim
- source、filterの分離という考え方
  - sourceの例
    - buffer、snippet、辞書、file
  - filterの例
    - fuzzy filter（"hf"で、"hoge_foo"にマッチする）
    - 編集距離順にソートするfilter

---

### スニペット
- [vim-vsnip](https://github.com/hrsh7th/vim-vsnip) スニペット定義はVSCode方式。ミニマルで扱いやすい。
- [ultisnips](https://github.com/SirVer/ultisnips) VSCodeよりもはるかに高機能。

```c
// Cのfor文の例
for (${1:size_t} ${2:i} = ${3:0}; $2 < ${4:length}; $2++) {
  $0
}
```

```tex
% texでよく使うやつ
図\ref{$1}
```

---

### Git操作
- [gina.vim](https://github.com/lambdalisue/gina.vim) Git操作全般。ターミナルに戻らずに直感的に操作できる。
- [git-messanger.vim](https://github.com/rhysd/git-messenger.vim) 行ごとにコミット情報が出せる。

![drop-shadow](git_messenger.png)

---

### Vimの組み込み機能拡張プラグイン
- [vim-sandwich](https://github.com/machakann/vim-sandwich) ()や""で囲むoperatorを実現する。
- [clever-f](https://github.com/rhysd/clever-f.vim) `f`コマンドを拡張。飛べる文字をハイライトしてくれる。
- [vim-swap](https://github.com/machakann/vim-swap) 関数の引数を一発で入れ替え。
- [undotree](https://github.com/mbbill/undotree) 変更履歴の一覧表示。

---

### 見た目を改善するプラグイン
#### カラースキーム
- [iceberg](https://github.com/cocopon/iceberg.vim): コントラスト低め
- [gruvbox-material](https://github.com/sainnhe/gruvbox-material)
- [solarized](https://github.com/altercation/vim-colors-solarized): VSCodeにもあるやつ
- [shirotelin](https://github.com/yasukotelin/shirotelin): 白背景だけど見やすい
- その他たくさん...

![bg drop-shadow right:50% 80%](colorswatch.png)

[colorswat](https://colorswat.ch/vim/)というサイトで、カラースキームを見比べることができる。

---

#### ステータスライン
- [lightline](https://github.com/itchyny/lightline.vim)

![drop-shadow](https://raw.githubusercontent.com/wiki/itchyny/lightline.vim/image/solarized_light.png)

<!-- Scoped style -->
<style scoped>
h5 {
  font-size: 20px;
}
</style>

##### https://raw.githubusercontent.com/wiki/itchyny/lightline.vim/image/solarized_light.png

---

### その他便利なプラグイン
- [vim-quickrun](https://github.com/thinca/vim-quickrun) 一発でコンパイル&実行。
- [caw.vim](https://github.com/tyru/caw.vim) コメントアウトプラグイン。
- [calendar.vim](https://github.com/itchyny/calendar.vim) カレンダーを出せる。
- [indentLine](https://github.com/Yggdroot/indentLine) インデントを可視化する。
- [vim-tex](https://github.com/lervag/vimtex) texのプレビュー等。
- [skkeleton](https://github.com/vim-skk/skkeleton) 変態的な日本語入力機構である[SKK](https://dic.nicovideo.jp/a/skk)をVimで実現する。IMEを切り換える必要がない。

---

## なぜVSCodeではなく、Vimを使うのか
- すべてを自分の思い通りにしたい。
  - VSCodeは拡張機能や設定で、ある程度ユーザーの思い通りにすることはできる。
  - しかし、エディタにもとから組込まれている機能については、不要な機能を削ったり、他の拡張に置きかえることはできない。
- マウスを使いたくない (Vim拡張を使ってもマウス操作を強いられることがある) 

---

## Vimに興味を持った方へ
まずは[実践Vim](https://www.amazon.co.jp/%E5%AE%9F%E8%B7%B5Vim-%E6%80%9D%E8%80%83%E3%81%AE%E3%82%B9%E3%83%94%E3%83%BC%E3%83%89%E3%81%A7%E7%B7%A8%E9%9B%86%E3%81%97%E3%82%88%E3%81%86%EF%BC%81-%E3%82%A2%E3%82%B9%E3%82%AD%E3%83%BC%E6%9B%B8%E7%B1%8D-%EF%BC%A4%EF%BD%92%EF%BD%85%EF%BD%97-%EF%BC%AE%EF%BD%85%EF%BD%89%EF%BD%8C-ebook/dp/B00HWLJI3U)を読みましょう。

#### おすすめ入門記事
「vim プラグイン」とかでGoogle検索上位に出てくるプラグインはすでに古くなっていることも多い...
- [上達したいVim初心者のための設定・プラグインの見つけ方、学び方](https://eh-career.com/engineerhub/entry/2019/01/28/103000) 
  基本的な心構えについて。記事内で言及されているvim-polyglotは現在はおすすめしません。
- [無人島に持っていく(Neo)vimプラグイン10選 (TS開発環境編)](https://zenn.dev/yano/articles/vim_plugin_top_10)
- [Neovim v0.5リリース記念 v0.5の新機能を紹介します【前編】](https://lab.mo-t.com/blog/neovim-v05-introduction-new-features-part-1) 
  Neovimについて知りたい方向け。

---

# :qall!
