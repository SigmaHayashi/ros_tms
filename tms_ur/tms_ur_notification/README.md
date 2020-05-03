# tms_ur_notification

Googleのアプリケーション開発プラットフォームFirebaseの機能を使って，スマートフォンにプッシュ通知を送信するパッケージ

ROSからFirebase Cloud Messaging (FCM)を使ってプッシュ通知を発行できる


# Firebaseの導入

tms_ur_notificationはGoogleのアプリケーション開発プラットフォーム"Firebase"を用いて実装した．Firebase Cloud Messaging (以下FCM)の機能を用いて，クラウド経由でスマートフォン端末へのプッシュ通知を発行する．

Firebaseプロジェクトの作成にはGoogleアカウントが必要で，アカウントでプロジェクトを管理する．

tms_ur_notificationのようにサーバプログラムから通知を発行する場合は，プロジェクトごとにハッシュキーのようなものが必要となる．そのキーを公開＆共有できないため，キーの作成方法を説明する．

参考 : [サーバーにFirebase Admin SDKを追加する](https://firebase.google.com/docs/admin/setup/)  
※Python，Linuxの項目を参照．


## Firebase Admin SDKのインストール
```
$ sudo pip install firebase-admin
```


## Firebaseプロジェクトの作成
https://firebase.google.com/

から，
* "使ってみる"を選択
* Googleアカウントでログイン
* "プロジェクトを追加"で新しいプロジェクトを作成
     * プロジェクト名はなんでもいい


## Firebaseサービスアカウント用の秘密鍵ファイルの生成
作成したFirebaseプロジェクトのコンソールから，"設定"→"サービスアカウント"と進む．

"新しい秘密鍵の生成"→"キーを生成"と進み，キーを含むJSONファイルを保存する．


## 環境変数の設定
.bashrcに追記
```
# 秘密鍵ファイルのパスを指定
export GOOGLE_APPLICATION_CREDENTIALS="/home/user/Documents/service-account-file.json"
```

## 以下の方法でノードを実行できれば成功
上手くいかなければ質問してください．


# スマートフォンアプリケーション
スマートフォンのアプリケーション"tms_ur Notification Client"の導入については，以下を参照

tms_ur Notification Client : https://github.com/SigmaHayashi/tms_ur-Notification-Client


# ノードの実行方法

```
$ roscore
$ rosrun tms_ur_notification notification_server.py
```


# 通知の発行方法
送信する通知の

* タイトル
* 内容文
* 通知をタップした時に起動するアプリケーション名

を指定してサービスを呼び出す


## 例
```
$ rosservice call /tms_ur_notification "title: 'Move Task'
body: 'smartpal5_2 will go to bed (x=8.04, y = 2.3)'
start_app: 'Smart Previewed Reality'"
```
