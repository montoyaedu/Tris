pipeline {
  agent {
    dockerfile true
  }
  stages {
    stage('compile') {
      steps {
        sh 'echo Hello, OK=$OK!'
        sh 'make clean'
      }
    }
  }
}
