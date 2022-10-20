pipeline {
    agent any

    stages {
        stage ('Build') {
            steps {
                bat 'g++ -o f HotelManagementProject.cpp'
                bat './f.exe'
                
            }
        }
    }
}
