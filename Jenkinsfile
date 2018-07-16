pipeline {
  agent any
  stages {
    stage('compile') {
      steps {
        sh 'make clean all test'
      }
    }
  }
}