pipeline {
    agent any

    stages {
        stage ('Build') {
            steps {
                bat '''gcc HotelManagementProject.cpp-o outputfile.exe '''
                bat ''' outputfile.exe '''
            }
        }
    }
