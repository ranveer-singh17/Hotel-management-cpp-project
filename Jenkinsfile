pipeline {
    agent any

    stages {
        stage ('Build') {
            steps {
                powershell '''g++ -o f HotelManagementProject.cpp'''
                powershell '.\\f.exe'
            }
        }
    }
}
