# table = driver.find_element('table#jobs')
# table.find_element(:css, 'tr').each do |tr|
#   location = tr.find_element(:css, 'td:nth-child(2)').text
#   postcode = location.split(',').last
#   if postcode.split(' ').first == 'SE4'
#     tr.find_element(:button).click
#   end
# end

#importing the files
require 'rubygems'
require 'selenium-webdriver'
require 'mail'
require 'nokogiri'
require 'capybara'

options = { :address              => "smtp.gmail.com",
            :port                 => 465,
            :domain               => 'gmail.com',
            :user_name            => 'amrozinski@gmail.com',
            :password             => 'V`@>L>N4SPia?B~)qyxitb="0',
            :authentication       => :login,
            :ssl                  => true,
            :openssl_verify_mode  => 'none'
          }

Mail.defaults do
  delivery_method :smtp, options
end

def send_that(recipient = 'amrozinski@gmail.com',subjects="prebook",body_message="test")
  Mail.deliver do
     to recipient
     from 'amrozinski@gmail.com'
     subject subjects
     body body_message
     add_file  "/home/artur/Desktop/Selenium/prebook/job#{Time.new.strftime("%k:%M")}.png"
  end
end

driver = Selenium::WebDriver.for :chrome
wait = Selenium::WebDriver::Wait.new(:timeout => 10)


driver.get 'https://addleedrivers.co.uk/drp/#/driver/login'
wait.until { driver.page_source.include?("password") }
driver.find_element(id: 'driver-login-username').send_keys("12747")
driver.find_element(id: 'driver-login-password').send_keys("Albert12", :enter)

POSTCODES = [' RG',  ' OX', ' SN', ' GU', " SO", ' GL',' SP',' HP', 'allocated']

loop do
  driver.get "https://addleedrivers.co.uk/drp/#/driver/prebook"
  if POSTCODES.any? {|pc| @a = pc if driver.page_source.include?(pc)}
    driver.manage.window.maximize
    img = driver.screenshot_as(:png)
    File.open("/home/artur/Desktop/Selenium/prebook/job#{Time.new.strftime("%k:%M")}.png", 'w+') do |fh|
      fh.write img
    end
    send_that('zukowski.adam@yahoo.com', #recipient
              "Q06. Job found in #{@a} post code", #subject
              'https://addleedrivers.co.uk/drp/#/driver/prebook') #
    break
  end
  sleep rand(0.3...0.51)
end

find = page_source
driver.quit
