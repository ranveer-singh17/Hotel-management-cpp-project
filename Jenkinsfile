pipeline {
    agent any

    stages {
        stage ('Build') {
            steps {
                bat 'gcc -o f HotelManagementProject.cpp'
                bat './f.exe'
                
            }
        }
    }
}
