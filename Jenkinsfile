pipeline {
    agent any

    stages {
        stage ('Build') {
            steps {
                powershell '''g++ -o program HotelManagementProject.cpp
                .\\program.exe'''
            }
        }
    }
}
