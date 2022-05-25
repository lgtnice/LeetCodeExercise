function ReplaceSpecificString()
{
    Param(
    $Filename,
    $Oldvalue,
    $Newvalue
    )
    $content = Get-Content $Filename
    Clear-Content $Filename
    foreach($line in $content) {
        $liner=$line.Replace($Oldvalue, $Newvalue)
        Add-Content $Filename -Value $liner
    }
}

$scriptPath = Split-Path -Parent $MyInvocation.MyCommand.Definition
# 命令Get-Location，也可以获取当前脚本的所在目录
Set-Location $scriptPath

$filePath = ".\Attachment"
$originName = 'ReplaceMe'
$targetName = '1002查找常用字符'

#不要在模板文件里面使用[]，否则复制文件失败

New-Item -Path ".\$targetName" -ItemType Directory
foreach($fileItem in (Get-ChildItem $filePath))
{
    #echo "In Progress, copying  $filePath\$fileItem"
    Copy-Item $fileItem.FullName -Destination ".\$targetName"
}

foreach($fileItem in (Get-ChildItem ".\$targetName"))
{
    #Another way which is same totally
    #ReplaceSpecificString -FileName $fileItem.FullName -Oldvalue $originName -Newvalue $targetName
    ReplaceSpecificString $fileItem.FullName $originName $targetName
    $newFileName = $fileItem.Name.Replace($originName,$targetName)
    Rename-Item -Path $fileItem.FullName -NewName $newFileName
}

#Write-Host("ABC {0} {1}" -f $args[0],$filePath)
<# comment #>
#support pipeline
#[parameter(Mandatory=$true, ValueFromPipeline=$true)]
#allow multi time to be run
#process{}
#scope command,for invoke the function in another script file.
#. "psFilePath"