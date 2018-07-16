pipeline {
  agent {
    dockerfile {
      filename 'Dockerfile'
    }

  }
  stages {
    stage('compile') {
      steps {
        sh 'make clean all test'
      }
    }
  }
}