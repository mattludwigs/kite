# server


[![CircleCI](https://circleci.com/gh/yourgithubhandle/server/tree/master.svg?style=svg)](https://circleci.com/gh/yourgithubhandle/server/tree/master)


**Contains the following libraries and executables:**

```
server@0.0.0
│
├─test/
│   name:    TestServer.exe
│   main:    TestServer
│   require: server.lib
│
├─library/
│   library name: server.lib
│   namespace:    Server
│   require:
│
└─executable/
    name:    ServerApp.exe
    main:    ServerApp
    require: server.lib
```

## Developing:

```
npm install -g esy
git clone <this-repo>
esy install
esy build
```

## Running Binary:

After building the project, you can run the main binary that is produced.

```
esy x ServerApp.exe 
```

## Running Tests:

```
# Runs the "test" command in `package.json`.
esy test
```
