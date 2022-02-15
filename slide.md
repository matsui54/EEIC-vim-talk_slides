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


# 目次

- 自己紹介
- VimとNeovim
- プラグインの紹介
  - ファイル検索・ファイラー
  - 自動補完
  - LSP
  - git操作
  - Vimの組み込み機能拡張系
  - 見た目系
  - サクッと実行
  - 日本語入力

---

## 自己紹介

- 松井晴輝(GitHub ハンドルネーム: matsui54)
- Vim歴: 2年弱
- Vim戦闘力[^1]: 2400
- Vimを始めたきっかけ: 

![bg right:30% fit](https://2.bp.blogspot.com/-bhubAsodZjU/W5IAOpox-xI/AAAAAAABOzA/wBvRPnVclBEygI1SIvx9GyP2aaVWcmqjwCLcBGAs/s800/undou_deadlisft_man.png)

[^1]: https://vim-jp.org/vim-users-jp/2009/07/10/Hack-39.html

---

## VimとNeovim
### Vim
- 互換性重視
- どの環境でも入れやすい
- 一応新機能も追加されているが、なんか微妙...

---

### Neovim
- モダンな機能がどんどん追加されている
  ex: LSP（VSCodeのような言語機能）, TreeSitter (よりよいシンタックスハイライト)
- Better defaults
- Lua（Vim scriptよりも数十倍速い）という言語で拡張可能（もちろんVim scriptも動く）


特に理由がなければ、Neovimを使うことをおすすめします。

---

## Pluginの紹介

---

### ファイル検索
- ファジーファインダー
  - :star: [denite.nvim]()
  - [Telescope.nvim](https://github.com/nvim-telescope/telescope.nvim) （Neovim専用）
Vimにはファジーファインダーがたくさんあるので、興味のあるかたは[こちらの記事](https://zenn.dev/yutakatay/articles/vim-fuzzy-finder)をどうぞ。

- ファイラー
  - :star: [defx.nvim]()
  - [fern.vim]() 初心者におすすめ。

![bg right:30% fit](./vscode_file.png)

---

### Language Server Protocol (LSP)

昔は、便利な編集機能（定義ジャンプや関数や変数の補完）は言語ごとに実装され、そのツールごとにエディタが対応する必要があった。

LSPはこれらの便利機能をプロトコルとして定義し、エディタはLSPの仕様を実装すればどの言語のLanguage Serverの機能も使えるようになった。

=> Vim/Emacs等でもLSP クライアントを入れればVSCodeの編集機能を使えるように!

![w:600](https://code.visualstudio.com/assets/api/language-extensions/language-server-extension-guide/lsp-languages-editors.png)

---

### VimのLSPクライアント
- [vim-lsp]() (Neovimではない) Vimでも動く。
- Neovim builtin LSP: Neovimの組み込みLSPクライアント。動作が速いがLuaで設定する必要あり。

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
- :star: [ddc.vim]() 最強のカスタマイズ性。
- [coc.nvim]() "Make your Vim/Neovim as smart as VSCode."がモットー。
  初心者におすすめ。

![drop-shadow](ddc.png)

---

### ddc.vim

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
- [gina.vim]() Git操作全般。ターミナルに戻らずに直感的に操作できる。
- [git-messanger.vim](https://github.com/rhysd/git-messenger.vim) 行ごとにコミット情報が出せる。

![drop-shadow](git_messenger.png)

---

### Vimの組み込み機能拡張プラグイン
- [vim-sandwich](https://github.com/machakann/vim-sandwich) ()や""で囲むoperatorを実現する。
- [clever-f]() `f`コマンドを拡張。飛べる文字をハイライトしてくれる。
- [vim-swap]() 関数の引数を一発で入れ替え。
- [undotree]() 変更履歴の一覧表示。

---

### 見た目を改善するプラグイン
#### カラースキーム
- :star: [iceberg](): コントラスト低め
- [gruvbox](): 有名
- [solarized](https://github.com/altercation/vim-colors-solarized): VSCodeにもあるやつ
- [shirotelin](): 白背景だけど見やすい
- その他たくさん...

![bg drop-shadow right:50% 80%](colorswatch.png)

[colorswat](https://colorswat.ch/vim/)というサイトで、カラースキームを見比べることができる。

---

#### ステータスライン
- [lightline](https://github.com/itchyny/lightline.vim)

![drop-shadow](https://raw.githubusercontent.com/wiki/itchyny/lightline.vim/image/solarized_light.png)

---

### その他便利なプラグイン
- [vim-quickrun]() 一発でコンパイル&実行。
- [caw.vim]() コメントアウトプラグイン。
- [calendar.vim]() カレンダーを出せる。
- [indentLine]() インデントを可視化する。
- [vim-tex]() texのプレビュー

---

## 興味を持った方へ
まずは[実践Vim](https://www.amazon.co.jp/%E5%AE%9F%E8%B7%B5Vim-%E6%80%9D%E8%80%83%E3%81%AE%E3%82%B9%E3%83%94%E3%83%BC%E3%83%89%E3%81%A7%E7%B7%A8%E9%9B%86%E3%81%97%E3%82%88%E3%81%86%EF%BC%81-%E3%82%A2%E3%82%B9%E3%82%AD%E3%83%BC%E6%9B%B8%E7%B1%8D-%EF%BC%A4%EF%BD%92%EF%BD%85%EF%BD%97-%EF%BC%AE%EF%BD%85%EF%BD%89%EF%BD%8C-ebook/dp/B00HWLJI3U)を読みましょう。

#### おすすめ入門記事
「vim プラグイン」とかでGoogle検索上位に出てくるプラグインはすでに古くなっていることも多い...
- [上達したいVim初心者のための設定・プラグインの見つけ方、学び方](https://eh-career.com/engineerhub/entry/2019/01/28/103000) 
  基本的な心構えについて。記事内で言及されているvim-polyglotは現在はおすすめしません。
- [無人島に持っていく(Neo)vimプラグイン10選 (TS開発環境編)](https://zenn.dev/yano/articles/vim_plugin_top_10)
- [Neovim v0.5リリース記念 v0.5の新機能を紹介します【前編】](https://lab.mo-t.com/blog/neovim-v05-introduction-new-features-part-1) Neovimについて知りたい方向け。
