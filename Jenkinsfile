pipeline {
    agent any

    stages {
        stage ('Build stage') {
            steps {
                bat 'g++ -o f HotelManagementProject.cpp'
                bat 'f.exe'
                
            }
        }
    }
}
